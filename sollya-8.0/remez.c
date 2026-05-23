/*

  Copyright 2006-2022 by

  Laboratoire de l'Informatique du Parallelisme,
  UMR CNRS - ENS Lyon - UCB Lyon 1 - INRIA 5668,

  LORIA (CNRS, INPL, INRIA, UHP, U-Nancy 2),

  Laboratoire d'Informatique de Paris 6, equipe PEQUAN,
  UPMC Universite Paris 06 - CNRS - UMR 7606 - LIP6, Paris, France,

  Laboratoire d'Informatique de Paris 6 - Équipe PEQUAN
  Sorbonne Universités
  UPMC Univ Paris 06
  UMR 7606, LIP6
  Boîte Courrier 169
  4, place Jussieu
  F-75252 Paris Cedex 05
  France,

  Sorbonne Université
  CNRS, Laboratoire d'Informatique de Paris 6, LIP6
  F - 75005 Paris
  France,

  Centre de recherche INRIA Sophia Antipolis Mediterranee,
  Equipes APICS, FACTAS,
  Sophia Antipolis, France

  and by

  Department of Computer Science & Engineering
  UAA College of Engineering
  University of Alaska Anchorage.

  Contributors Ch. Lauter, S. Chevillard

  christoph.lauter@christoph-lauter.org
  sylvain.chevillard@ens-lyon.org

  This software is a computer program whose purpose is to provide an
  environment for safe floating-point code development. It is
  particularly targeted to the automated implementation of
  mathematical floating-point libraries (libm). Amongst other features,
  it offers a certified infinity norm, an automatic polynomial
  implementer and a fast Remez algorithm.

  This software is governed by the CeCILL-C license under French law and
  abiding by the rules of distribution of free software.  You can  use,
  modify and/ or redistribute the software under the terms of the CeCILL-C
  license as circulated by CEA, CNRS and INRIA at the following URL
  "http://www.cecill.info".

  As a counterpart to the access to the source code and  rights to copy,
  modify and redistribute granted by the license, users are provided only
  with a limited warranty  and the software's author,  the holder of the
  economic rights,  and the successive licensors  have only  limited
  liability.

  In this respect, the user's attention is drawn to the risks associated
  with loading,  using,  modifying and/or developing or reproducing the
  software by the user in light of its specific status of free software,
  that may mean  that it is complicated to manipulate,  and  that  also
  herefore means  that it is reserved for developers  and  experienced
  professionals having in-depth computer knowledge. Users are therefore
  encouraged to load and test the software's suitability as regards their
  requirements in conditions enabling the security of their systems and/or
  data to be ensured and,  more generally, to use and operate it in the
  same conditions as regards security.

  The fact that you are presently reading this means that you have had
  knowledge of the CeCILL-C license and that you accept its terms.

  This program is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*/

#include <gmp.h>
#include <mpfr.h>
#include "chain.h"
#include "general.h"
#include "infnorm.h"
#include "execute.h"
#include "remez.h"
#include <stdio.h> /* fprintf, fopen, fclose, */
#include <stdlib.h> /* exit, free, mktemp */
#include <errno.h>

#define coeff(i,j,n) ((i)-1)*(n)+(j)-1
#define NEWTON_STEPS 2

void myPrintValue(mpfr_t *x, mp_prec_t prec) {
  mpfr_t y;
  mpfr_init2(y,prec);
  mpfr_set(y,*x,GMP_RNDN);
  printValue(&y);
  mpfr_clear(y);
}

void printMatrix(mpfr_t *M, int n) {
  int i,j;
  sollyaPrintf("[");
  for(i=1;i<=n;i++) {
    for(j=1;j<=n;j++) {
      myPrintValue(&M[coeff(i,j,n)],53); if(j!=n) sollyaPrintf(", ");
    }
    if(i!=n) sollyaPrintf(";\n");
  }
  sollyaPrintf("]\n");
  return;
}

void printMessageMatrix(int verb, mpfr_t *M, int n) {
  int i,j;
  printMessage(verb,SOLLYA_MSG_CONTINUATION,"[");
  for(i=1;i<=n;i++) {
    for(j=1;j<=n;j++) {
      printMessage(verb,SOLLYA_MSG_CONTINUATION,"%.15v",M[coeff(i,j,n)]); if(j!=n) printMessage(verb,SOLLYA_MSG_CONTINUATION,", ");
    }
    if(i!=n) printMessage(verb,SOLLYA_MSG_CONTINUATION,";\n");
  }
  printMessage(verb,SOLLYA_MSG_CONTINUATION,"]\n");
  return;
}

void system_solve(mpfr_t *res, mpfr_t *M, mpfr_t *b, int n, mp_prec_t prec) {
  chain *i_list=NULL;
  chain *j_list=NULL;
  chain *curri;
  chain *currj;
  int i0, j0, i, j, k;
  int *var;
  mpfr_t max,lambda;
  int *order_i = safeCalloc(n,sizeof(int));
  int *order_j = safeCalloc(n,sizeof(int));

  mpfr_init2(max, 53);
  mpfr_init2(lambda, prec);

  for(i=1;i<=n;i++) {
    var = safeMalloc(sizeof(int));
    *var = i;
    i_list = addElement(i_list, (void *)var);
  }
  for(j=1;j<=n;j++) {
    var = safeMalloc(sizeof(int));
    *var = j;
    j_list = addElement(j_list, (void *)var);
  }


  /* Triangulation by Gaussian elimination */
  i0 = j0 = -1;
  for(k=1;k<=n;k++) {
    mpfr_set_d(max, 0., GMP_RNDN); /* exact */

    /* In this part, we search for the bigger element of the matrix */
    curri = i_list;
    while(curri!=NULL) {
      currj = j_list;
      while(currj!=NULL) {
	i = *(int *)(curri->value);
	j = *(int *)(currj->value);
	if(mpfr_cmpabs(M[coeff(i,j,n)],max)>=0) {
	  i0 = i;
	  j0 = j;
	  mpfr_set(max, M[coeff(i,j,n)], GMP_RNDN);
	}
	currj = currj->next;
      }
      curri = curri->next;
    }

    i_list = removeInt(i_list, i0);
    j_list = removeInt(j_list, j0);

    order_i[k-1] = i0;
    order_j[k-1] = j0;

    /* Here we update the matrix and the second member */
    curri = i_list;
    while(curri!=NULL) {
      i = *(int *)(curri->value);
      mpfr_div(lambda, M[coeff(i,j0,n)], M[coeff(i0,j0,n)], GMP_RNDN);
      mpfr_neg(lambda, lambda, GMP_RNDN);

      currj = j_list;
      while(currj!=NULL) {
	j = *(int *)(currj->value);
	mpfr_fma(M[coeff(i,j,n)], lambda, M[coeff(i0,j,n)], M[coeff(i,j,n)], GMP_RNDN);
	currj = currj->next;
      }

      mpfr_fma(b[i-1], lambda, b[i0-1], b[i-1], GMP_RNDN);
      mpfr_set_d(M[coeff(i,j0,n)], 0., GMP_RNDN); /* this line is not useful strictly speaking */
      curri = curri->next;
    }
  }
  /*********************************************************************/


  /* Resolution of the system itself */
  for(i=1;i<=n;i++) {
    var = safeMalloc(sizeof(int));
    *var = i;
    i_list = addElement(i_list, (void *)var);
  }

  for(k=n;k>=1;k--) {
    i0 = order_i[k-1];
    j0 = order_j[k-1];
    mpfr_div(res[j0-1], b[i0-1], M[coeff(i0,j0,n)], GMP_RNDN);
    i_list = removeInt(i_list, i0);

    curri = i_list;
    while(curri!=NULL) {
      i = *(int *)(curri->value);
      mpfr_neg(M[coeff(i,j0,n)], M[coeff(i,j0,n)], GMP_RNDN);
      mpfr_fma(b[i-1], M[coeff(i,j0,n)], res[j0-1], b[i-1], GMP_RNDN);
      curri=curri->next;
    }
  }

  safeFree(order_i);
  safeFree(order_j);
  freeChain(i_list, freeIntPtr);
  freeChain(j_list, freeIntPtr);
  mpfr_clear(max);
  mpfr_clear(lambda);
  return;
}


/* Bubble sort */
void sollya_mpfr_sort(mpfr_t *vect, int n, mp_prec_t prec) {
  int i,j;
  mpfr_t var;

  mpfr_init2(var, prec);

  for(i=1;i<=n-1;i++) {
    for(j=n;j>=i+1;j--) {
      if(mpfr_cmp(vect[j-1], vect[j-2])<=0) {
	mpfr_set(var, vect[j-1], GMP_RNDN);
	mpfr_set(vect[j-1], vect[j-2], GMP_RNDN);
	mpfr_set(vect[j-2], var, GMP_RNDN);
      }
    }
  }

  mpfr_clear(var);
  return;
}


/* Constructs the tree corresponding to p = sum(coeff(i) monomials[i])
   The array coeff is supposed to have at least as many elements as monomials
*/
node *constructPolynomialFromExpressions(node **coeffs, chain *monomials) {
  chain *curr;
  node *poly;
  int i = 0;

  poly =  makeConstantDouble(0.0);
  for(curr = monomials;curr != NULL;curr=curr->next) {
    poly = makeAdd(poly, makeMul(copyTree(coeffs[i]), copyTree(curr->value)));
    i++;
  }
  return addMemRef(poly);
}

/* Constructs the tree corresponding to p = sum(coeff(i) * monomials[i])
   where both coeffs and monomials are given as chained lists.
   The array coeff is supposed to have at least as many elements as monomials.
*/
node *constructPolyFromMpfrChain(chain *coeffs, chain *monomials) {
  chain *curr;
  chain *c;
  node *poly;

  poly =  makeConstantDouble(0.0);
  c = coeffs;
  for(curr = monomials;curr != NULL;curr=curr->next) {
    poly = makeAdd(poly, makeMul(makeConstant(*(mpfr_t *)(c->value)), copyTree(curr->value)));
    c = c->next;
  }
  return addMemRef(poly);
}

/* Constructs the tree corresponding to p = sum(coeff(i) X^monomials[i])
   The array coeff is supposed to have at least as many elements as monomials
*/
node *constructPolynomial(mpfr_t *coeff, chain *monomials) {
  int i=1;
  int n;
  chain *curr;
  node *poly;

  poly =  makeConstantDouble(0.0);

  curr = monomials;
  while(curr != NULL) {
    n = *((int *)(curr->value));
    poly = makeAdd( makeMul( makeConstant(coeff[i-1]),
                             makePow(makeVariable(), makeConstantInt(n))
                             ),
                    poly
                    );
    i++;
    curr = curr->next;
  }

  return addMemRef(poly);
}



/* This function finds an approximate zero of a function f
   (which derivative is f_diff) in the interval [a;b]
   using x0 as an initial guess of the zero
   If n=0 the algorithm stops when the computed zero is
   an estimation of the real zero, with an accuracy of
   approximately prec bits.
   If n<>0, n steps are computed.
   The algorithm uses Newton's method.
   It is assumed that f(a)f(b)<=0 and x0 in [a;b]
   If x0=NULL the algorithm is free to use any initial guess
*/
void findZero(mpfr_t res, node *f, node *f_diff, mpfr_t a, mpfr_t b, int sgnfa, mpfr_t *x0, int n, mp_prec_t prec) {

  /* Sketch of the algorithm :
     During the algorithm, we will work with an interval [u,v]
     that surely contains a zero of f.
     Whenever a step of Newton's algorithm does not work, we perform a bisection step on [u,v]
     to ensure the convergence of the algorithm.

     1) It is necessary that [u,v] does not contain 0. This ensures that the range of
     possible exponents for x is bounded.

     So, if 0<a or b<0,  let [u,v]=[a,b] and go directly to step 2.

     Otherwise:
     Let epsa= max(-2^(-2p), a)    and   epsb = min(2^(-2p), b):
     hence a <= epsa <= 0 <= epsb <= b.
     Let signepsa = sign(f(epsa)), sign0 = sign(f(0)) and signepsb = sign(f(epsb)).
     Here sign can be -1,0,1 or NaN if the evaluation of f fails.
     We separate the different cases for (signepsa, sign0, signepsb):

     (   *       0      *   ) -> f(0)=0 exactly
     (   0       *      *   ) -> f(epsa)=0 exactly
     (   *       *      0   ) -> f(epsb)=0 exactly
     (-sgnfa     *      *   ) -> we can set [u,v] = [a, epsa] (note that epsa<0 in this case)
     (   *       *     sgnfa) -> we can set [u,v] = [epsb, b] (note that epsb>0 in this case)

     (   *     sgnfa  -sgnfa) -> f changes its sign in [0,epsb] but f(0) != 0.
                                 We look for epsb' = 2^(-E) bisecting on the value of E, such
                                 that sgn(f(epsb')) = sgnfa and set [u,v] = [epsb', epsb]
                                 We arbitrarily decide to stop the bisection process after a
                                 given number of iteration, and if we are still successless,
                                 we declare that the zero of f cannot be determined accurately.
                                 We can return the last value of epsb' with an error message.
     ( sgnfa  -sgnfa    *   ) -> idem with [epsa,0]

     ( sgnfa    NaN   -sgnfa) -> f changes its sign in [epsa, epsb].
                                 It is likely that f(0)=0 but we cannot prove it.
                                 We can return 0 with an error message.

     ( sgnfa    NaN     NaN ) -> This case is likely to be b=0 (hence epsb=0)
                                 We cannot prove much but it is reasonnable to return 0
     (  NaN     NaN   -sgnfa) -> idem with a=0
     (  NaN     NaN     NaN ) -> idem with a=0=b

     (  *      sgnfa    NaN ) -> We are really in trouble here since f(0) is provably non zero
                                 but we do not know if f vanishes in [0,epsb] or [epsb, b].
                                 We should better stop with a huge ERROR
     (  NaN   -sgnfa     *  ) -> idem with [a, epsa] or [epsa, 0]


     2) Now we are sure that [u,v] does not contain 0.

     During the algorithm, we will consider an approximation x of the zero z of f.
     From x, we compute a new approximation xNew.
     We assume that xNew is a very good approximation of z. Thus we can estimate the
     relative error between x and z by |xNew-x|/|xNew|.
     If this error is smaller than 2^(-prec), x is an accurate estimation of z and a fortiori
     xNew is accurate as well.

     Let x be somewhere in [u,v] (in the beginning, x=x0 if x0 is defined and lies in [u,v]).
     We compute xNew = iterator(x) = x - f(x)/f'(x)

     If (xNew<u) or (xNew>v) or xNew=NaN, we perform a bisection step:
     replaced by either [u, m] of [m, u] where m=(u+v)/2 and xNew is defined as
     the middle of the new interval

     Otherwise: xNew gives a valid new value. We compute yNew=f(xNew).
     We have 4 cases depending on sgn(yNew):
        sgnfa -> we can replace [u,v] by [xNew,v]
       -sgnfa -> we can replace [u,v] by [u, xNew]
          0   -> xNew is an exact zero of f. We can stop
         NaN  -> we leave [u,v] as is. Most likely the iterator(xNew) will be NaN and the next
                 step will be a bisection step.
  */

  mpfr_t zero_mpfr, cutoff;
  mpfr_t u, v, epsa, fepsa, epsb, fepsb, f0;
  int sgnfepsa, sgnfepsb, sgnf0;
  int codefa, codeNegfa;
  int stop_algo = 0;
  int skip_step1 = 0;
  mp_prec_t prec_bounds;
  int r, i;

  node *iterator;
  node *temp;
  mpfr_t x, xNew, yNew, tmp_mpfr;
  int estim_prec, estim_prec2;
  int nbr_iter;

  /* Make compiler happy: */
  estim_prec = 12;
  nbr_iter = 2;
  /* End of compiler happiness */

  if (x0 != NULL) {
    printMessage(8,SOLLYA_MSG_ENTERING_NEWTONS_ALGORITHM,"Information (Newton's algorithm): entering in Newton's algorithm. Parameters are:\nInformation (Newton's algorithm): f = %b\nInformation (Newton's algorithm): a = %v\nInformation (Newton's algorithm): b = %v\nInformation (Newton's algorithm): x0 = %v\n",f,a,b,*x0);
  } else {
    printMessage(8,SOLLYA_MSG_ENTERING_NEWTONS_ALGORITHM,"Information (Newton's algorithm): entering in Newton's algorithm. Parameters are:\nInformation (Newton's algorithm): f = %b\nInformation (Newton's algorithm): a = %v\nInformation (Newton's algorithm): b = %v\n",f,a,b);
  }

  prec_bounds = (mpfr_get_prec(a)>mpfr_get_prec(b)) ? mpfr_get_prec(a) : mpfr_get_prec(b);
  if (prec>prec_bounds) prec_bounds = prec;

  mpfr_init2(u, prec_bounds);
  mpfr_init2(v, prec_bounds);
  mpfr_init2(zero_mpfr, prec);
  mpfr_init2(cutoff, 12);

  mpfr_set_si(zero_mpfr, 0, GMP_RNDN);
  mpfr_set_si(cutoff, 0, GMP_RNDN);

  if ( (mpfr_cmp_ui(a,0)>0) || mpfr_cmp_ui(b,0)<0 ) {
    mpfr_set(u, a, GMP_RNDU); /* exact */
    mpfr_set(v, b, GMP_RNDD); /* exact */
    skip_step1 = 1;
  }

  /**************    STEP 1 : removing zero from the range    **************/
  if (!skip_step1) {
    mpfr_init2(epsa, prec);
    mpfr_init2(epsb, prec);
    mpfr_init2(fepsa, 12);
    mpfr_init2(fepsb, 12);
    mpfr_init2(f0, 12);

    mpfr_set_si(epsa, -1, GMP_RNDU);
    mpfr_div_2ui(epsa, epsa, 2*prec, GMP_RNDU);
    if (mpfr_cmp(a,epsa)>0) mpfr_set(epsa, a, GMP_RNDU);

    mpfr_set_si(epsb, 1, GMP_RNDD);
    mpfr_div_2ui(epsb, epsb, 2*prec, GMP_RNDD);
    if (mpfr_cmp(epsb,b)>0) mpfr_set(epsb, b, GMP_RNDD);

    /* For the signs, we use the following convention:
       0 is coded by 0
       1 is coded by 1
       -1 is coded by 2
       NaN is coded by 3
    */
    r = evaluateFaithfulWithCutOffFast(f0, f, f_diff, zero_mpfr, cutoff, prec);
    if(r==0) mpfr_set_d(f0,0,GMP_RNDN);
    if (!mpfr_number_p(f0)) sgnf0 = 3;
    else {
      sgnf0 = mpfr_sgn(f0);
      if (sgnf0!=0) sgnf0 = (sgnf0>0) ? 1 : 2;
    }

    /* It might be that a==0, in which case epsa==0 and we do not want to */
    /* evaluate f again */
    if (mpfr_cmp_ui(a,0)==0) {
      mpfr_set(fepsa, f0, GMP_RNDN); /* exact */
      sgnfepsa = sgnf0;
    }
    else {
      r = evaluateFaithfulWithCutOffFast(fepsa, f, f_diff, epsa, cutoff, prec);
      if(r==0) mpfr_set_d(fepsa,0,GMP_RNDN);
      if (!mpfr_number_p(fepsa)) sgnfepsa = 3;
      else {
        sgnfepsa = mpfr_sgn(fepsa);
        if (sgnfepsa!=0) sgnfepsa = (sgnfepsa>0) ? 1 : 2;
      }
    }

    /* It might be that b==0, in which case epsb==0 and we do not want to */
    /* evaluate f again */
    if (mpfr_cmp_ui(b,0)==0) {
      mpfr_set(fepsb, f0, GMP_RNDN); /* exact */
      sgnfepsb = sgnf0;
    }
    else {
      r = evaluateFaithfulWithCutOffFast(fepsb, f, f_diff, epsb, cutoff, prec);
      if(r==0) mpfr_set_d(fepsb,0,GMP_RNDN);
      if (!mpfr_number_p(fepsb)) sgnfepsb = 3;
      else {
        sgnfepsb = mpfr_sgn(fepsb);
        if (sgnfepsb!=0) sgnfepsb = (sgnfepsb>0) ? 1 : 2;
      }
    }

    if (sgnfa>0) { codefa = 1; codeNegfa = 2; }
    else { codefa = 2; codeNegfa = 1; }

    /* Start examining all possible subcases */
    if (sgnf0==0) {
      printMessage(5, SOLLYA_MSG_NEWTON_ZERO_IS_EXACT_ZERO, "Information (Newton's algorithm): 0 is an exact 0.\n");
      mpfr_set(res, zero_mpfr, GMP_RNDN);
      stop_algo = 1;
    }
    else if (sgnfepsa==0) {
      printMessage(5, SOLLYA_MSG_NEWTON_AN_EXACT_ZERO_HAS_BEEN_FOUND, "Information (Newton's algorithm): an exact 0 has been discovered.\n");
      mpfr_set(res, epsa, GMP_RNDN);
      stop_algo = 1;
    }
    else if (sgnfepsb==0) {
      printMessage(5, SOLLYA_MSG_NEWTON_AN_EXACT_ZERO_HAS_BEEN_FOUND, "Information (Newton's algorithm): an exact 0 has been discovered.\n");
      mpfr_set(res, epsb, GMP_RNDN);
      stop_algo = 1;
    }
    /* From now on, all sgnf* belong to {1,2,3} */

    /* The cases (-sngfa, * *) can be separated into subcases: */
    else if (sgnfepsa==codeNegfa) {
      if ((sgnf0==codefa) || (sgnfepsb==codefa)) {
          printMessage(4, SOLLYA_MSG_NEWTON_FUNC_APPEARS_TO_HAVE_MORE_THAN_ONE_ZERO, "Warning (Newton's algorithm): the function has more than one zero in the interval.\n");
      }
      if ((sgnf0==3) && (sgnfepsb==codefa)) {
        printMessage(4, SOLLYA_MSG_NEWTON_ZERO_SEEMS_TO_BE_ZERO_NO_PROOF, "Warning (Newton's algorithm): 0 seems to be one of them but we cannot prove it.\n");
        mpfr_set(res, zero_mpfr, GMP_RNDN);
        stop_algo = 1;
      }
      else {
        mpfr_set(u, a, GMP_RNDD);
        mpfr_set(v, epsa, GMP_RNDU);
      }
    }
    /* From now on, sgnfepsa can only be 3 (NaN) or codefa */

    /* Symmetric case from the previous one: (*,*,sgnfa) */
    else if (sgnfepsb==codefa) {
      if (sgnf0==codeNegfa) {
        printMessage(4, SOLLYA_MSG_NEWTON_FUNC_APPEARS_TO_HAVE_MORE_THAN_ONE_ZERO, "Warning (Newton's algorithm): the function has more than one zero in the interval.\n");
      }
      mpfr_set(u, epsb, GMP_RNDD);
      mpfr_set(v, b, GMP_RNDU);
    }
    /* From now on, sgnfepsb can only be 3 (NaN) or codeNegfa */

    else if (sgnf0 == 3) {
      printMessage(2, SOLLYA_MSG_NEWTON_ZERO_SEEMS_TO_BE_ZERO_NO_PROOF, "Warning (Newton's algorithm): 0 seems to be an exact zero but we cannot prove it.\n");
      mpfr_set(res, zero_mpfr, GMP_RNDN);
      stop_algo = 1;
    }

    else if ( ((sgnfepsa==codefa) && (sgnf0==codeNegfa)) ||
              ((sgnf0==codefa) && (sgnfepsb==codeNegfa)) ) { /* We bisect over the exponents */
      /* For the bisection we use variable epsa whatever the sign */
      if (sgnf0==codefa) {
        mpfr_set(epsa, epsb, GMP_RNDN); /* exact */
        sgnfepsa = sgnfepsb;
      }
      mpfr_set(u, epsa, GMP_RNDN);

      i = 1;
      while (1) {
        mpfr_set_exp(epsa, 2*mpfr_get_exp(epsa));
        r = evaluateFaithfulWithCutOffFast(fepsa, f, f_diff, epsa, cutoff, prec);
        if(r==0) mpfr_set_d(fepsa,0,GMP_RNDN);
        if (!mpfr_number_p(fepsa)) sgnfepsa = 3;
        else {
          sgnfepsa = mpfr_sgn(fepsa);
          if (sgnfepsa!=0) sgnfepsa = (sgnfepsa>0) ? 1 : 2;
        }

        if (sgnfepsa == 0) {
          printMessage(5, SOLLYA_MSG_NEWTON_AN_EXACT_ZERO_HAS_BEEN_FOUND, "Information (Newton's algorithm): an exact 0 has been discovered.\n");
          mpfr_set(res, epsa, GMP_RNDN);
          stop_algo = 1;
          break;
        }
        else if (sgnfepsa == 3) {
          printMessage(2, SOLLYA_MSG_NEWTON_ALGORITHM_FAILS_DUE_TO_NUMERICAL_ISSUES, "Error (Newton's algorithm): failed due to numerical issues.\n");
          mpfr_set_nan(res);
          stop_algo = 1;
          break;
        }
        else if (sgnfepsa == sgnf0) {
          mpfr_set(v, epsa, GMP_RNDN);
          if (mpfr_cmp(u,v) > 0) {
            mpfr_set(v,u,GMP_RNDN);
            mpfr_set(u, epsa, GMP_RNDN);
          }
          break;
        }
        else {
          mpfr_set(u, epsa, GMP_RNDN);
        }

        i++;
        if (i==10) {
          printMessage(2, SOLLYA_MSG_NEWTON_ZERO_TOO_CLOSE_TO_ZERO_TO_BE_ACCURATE, "Warning (Newton's algorithm): the zero of f is too close to zero for being accurately determined.\n");
          mpfr_set(res, epsa, GMP_RNDN);
          stop_algo = 1;
          break;
        }
      }
    }
    else {
      printMessage(2, SOLLYA_MSG_NEWTON_ALGORITHM_FAILS_TO_LOCATE_ZERO, "Error (Newton's algorithm): failed to locate the zero\n");
      mpfr_set_nan(res);
      stop_algo = 1;
    }

    mpfr_clear(epsa);
    mpfr_clear(epsb);
    mpfr_clear(fepsa);
    mpfr_clear(fepsb);
    mpfr_clear(f0);
  }
  /*************************************************************************/



  /**************    STEP 2 : iterating Newton's algorithm    **************/
  if (!stop_algo) {
    mpfr_init2(x, prec);
    mpfr_init2(xNew, prec);
    mpfr_init2(yNew, 12);
    mpfr_init2(tmp_mpfr, 53);

    if(x0!=NULL) mpfr_set(x,*x0,GMP_RNDN);
    else { mpfr_add(x, u, v, GMP_RNDU); mpfr_div_2ui(x, x, 1, GMP_RNDN); }

    iterator = allocateNode();
    iterator->nodeType = SUB;
    temp = makeVariable();
    iterator->child1 = addMemRef(temp);

    temp = allocateNode();
    temp->nodeType = DIV;
    temp->child1 = copyTree(f);
    temp->child2 = copyTree(f_diff);
    iterator->child2 = addMemRef(temp);

    iterator = addMemRef(iterator);

    if (autosimplify || (f->nodeType != MEMREF) || (f_diff->nodeType != MEMREF)) {
      temp = simplifyTreeErrorfree(iterator);
      free_memory(iterator);
      iterator = temp;
    }

    /* Main loop */
    nbr_iter = 0;
    while(!stop_algo) {
      /* TODO: here we might adapt the precision of xNew by doubling it at each step */
      r = evaluateFaithfulWithCutOffFast(xNew, iterator, NULL, x, cutoff, prec);
      if(r==0) mpfr_set_d(xNew,0,GMP_RNDN);

      if ( ((mpfr_cmp(u, x)==0) && (mpfr_cmp(v, xNew)==0)) ||
           ((mpfr_cmp(v, x)==0) && (mpfr_cmp(u, xNew)==0)) ) {
        printMessage(5, SOLLYA_MSG_NEWTON_PERFORMING_BISECTION_STEP, "Information (Newton's algorithm): performing a bisection step\n");
        mpfr_add(xNew, u, v, GMP_RNDN);
        mpfr_div_2ui(xNew, xNew, 1, GMP_RNDN);
      }

      if( (mpfr_cmp(u,xNew)>0) || (mpfr_cmp(xNew,v)>0) || (!mpfr_number_p(xNew)) ) {
	printMessage(5, SOLLYA_MSG_NEWTON_PERFORMING_BISECTION_STEP, "Information (Newton's algorithm): performing a bisection step\n");
	mpfr_add(xNew,u,v,GMP_RNDN);
	mpfr_div_2ui(xNew, xNew, 1, GMP_RNDN);
	if (mpfr_cmp(x, xNew)==0) {
	  printMessage(5, SOLLYA_MSG_NEWTON_PERFORMING_TRISECTION_STEP, "Warning (Newton's algorithm): performing a trisection step.\n");
	  mpfr_sub(xNew,v,u,GMP_RNDN);
	  mpfr_div_ui(xNew, xNew, 3, GMP_RNDN);
	  mpfr_add(xNew, u, xNew, GMP_RNDN);
	}
      }

      r = evaluateFaithfulWithCutOffFast(yNew, f, f_diff, xNew, cutoff, prec); /* yNew=f[xNew] */
      if(r==0) mpfr_set_d(yNew, 0, GMP_RNDN);

      if (mpfr_number_p(yNew)) {
	if (mpfr_cmp_ui(yNew, 0)==0) {
	  printMessage(5, SOLLYA_MSG_NEWTON_AN_EXACT_ZERO_HAS_BEEN_FOUND, "Information (Newton's algorithm): an exact 0 has been discovered.\n");
	  mpfr_set(res, xNew, GMP_RNDN);
	  stop_algo = 1;
	}
	else {
	  if (mpfr_cmp_ui(yNew, 0)*sgnfa>0) mpfr_set(u, xNew, GMP_RNDN);
	  else mpfr_set(v, xNew, GMP_RNDN);
	}
      }


      mpfr_sub(tmp_mpfr, xNew, x, GMP_RNDU);
      if (!mpfr_zero_p(tmp_mpfr)) estim_prec= 1 + mpfr_get_exp(xNew) - mpfr_get_exp(tmp_mpfr);

      mpfr_sub(tmp_mpfr,v,u,GMP_RNDN);
      if(mpfr_cmp_abs(v,u)>0) estim_prec2 = 1 + mpfr_get_exp(u) - mpfr_get_exp(tmp_mpfr);
      else estim_prec2 = 1 + mpfr_get_exp(v) - mpfr_get_exp(tmp_mpfr);

      if(estim_prec2 > estim_prec) estim_prec = estim_prec2;

      nbr_iter++;
      if ( ((n!=0) && (nbr_iter==n)) || mpfr_equal_p(x,xNew) || (estim_prec>(int)prec)) {
	mpfr_set(res, xNew, GMP_RNDN);
	stop_algo=1;
      }

      mpfr_set(x,xNew,GMP_RNDN);
    }

    free_memory(iterator);
    mpfr_clear(x);
    mpfr_clear(xNew);
    mpfr_clear(yNew);
    mpfr_clear(tmp_mpfr);
  }

  /*************************************************************************/


  printMessage(7, SOLLYA_MSG_NEWTON_FINISHED_AFTER_NUMBER_OF_STEPS, "Information (Newton's algorithm): finished after %d steps.\n", nbr_iter);
  printMessage(8, SOLLYA_MSG_CONTINUATION, "Information (Newton's algorithm): x = %v\n",res);

  mpfr_clear(zero_mpfr);
  mpfr_clear(cutoff);
  mpfr_clear(u);
  mpfr_clear(v);

  return;
}

/* Just a wrapper */
void newton(mpfr_t res, node *f, node *f_diff, mpfr_t a, mpfr_t b, int sgnfa, mp_prec_t prec) {
  findZero(res, f, f_diff, a, b, sgnfa, NULL, 0, prec);
  return;
}

/******************************************/
/* Implementation of uncertifiedFindZeros */
/******************************************/

/* Because the bounds of the interval might be mpfr_t with much higher
   precision than prec, but we want the sample points to be at precion prec,
   except when they are equal to a bound, we use a dedicated structure */
#define REGULAR_POINT 0
#define INTERVAL_BOUND 1
typedef struct enhanced_mpfr_t_struct enhanced_mpfr_t;
struct enhanced_mpfr_t_struct {
  mpfr_t vals[2]; /* vals[REGULAR_POINT] used for regular sample points, vals[INTERVAL_BOUND] for the bounds */
  int i; /* which one to choose */
};
#define enhanced_mpfr_init2(x, prec1, prec2)    \
  do {                                          \
    mpfr_init2((x).vals[0], (prec1));           \
    mpfr_init2((x).vals[1], (prec2));           \
  } while(0)
#define enhanced_mpfr_clear(x)                  \
  do {                                          \
    mpfr_clear((x).vals[0]);                    \
    mpfr_clear((x).vals[1]);                    \
  } while(0)
#define get_mpfr(x) (x).vals[(x).i]

/* Intern function for uncertifiedFindZeros: assuming a step size h and a
   current point oldx in the research interval [a,b], computes the next point
   to be considered (that is, usually, oldx-h) and the corresponding value of
   the function. */
static inline void uncertifiedFindZeros_newpoint(enhanced_mpfr_t *newx, mpfr_t newy, mpfr_t oldx, mpfr_t a, mpfr_t h, node *tree, node *diff_tree, mpfr_t cutoff, mp_prec_t prec) {
  int r;
  newx->i = REGULAR_POINT; mpfr_sub(get_mpfr(*newx), oldx, h, GMP_RNDD);
  if ( (mpfr_cmp(oldx, a) > 0) && (mpfr_cmp(get_mpfr(*newx), a) < 0) ) {
    newx->i = INTERVAL_BOUND; mpfr_set(get_mpfr(*newx), a, GMP_RNDN);
  }

  if (mpfr_cmp(get_mpfr(*newx), a) < 0) {
    /* This makes as if we were looking at f on an interval [a', b] where a' < a but with f undefined on [a', a] */
    mpfr_set_nan(newy);
  }
  else {
    r = evaluateFaithfulWithCutOffFast(newy, tree, diff_tree, get_mpfr(*newx), cutoff, prec);
    if (r==0) mpfr_set_d(newy, 0, GMP_RNDN);
  }
}

static inline void uncertfiedFindZeros_shift(enhanced_mpfr_t x[3], mpfr_t y[3], mpfr_t a, mpfr_t h, node *tree, node *diff_tree, mpfr_t cutoff, mp_prec_t prec) {
  int k;
  for(k=0;k<=1;k++) {
    if (mpfr_cmp(get_mpfr(x[k+1]), a) == 0) {
      x[k].i = INTERVAL_BOUND;
    }
    else {
      x[k].i = REGULAR_POINT;
    }
    mpfr_set(get_mpfr(x[k]), get_mpfr(x[k+1]), GMP_RNDN); /* exact */
    mpfr_set(y[k], y[k+1], GMP_RNDN); /* exact */
  }
  uncertifiedFindZeros_newpoint(&x[2], y[2], get_mpfr(x[1]), a, h, tree, diff_tree, cutoff, prec);
}

/* Look for a zero of f in (x_left_bound, x_right_bound] based on the fact that
   f is known to take resp. values y_left_bound and y_right_bound.  One of them
   (but not more) might be NaN, in which case we shrink a little bit the
   interval to see if we manage to evaluate the function to something relevant.
   Returns NULL if no zero is found and a valid pointer to a dynamically
   allocated mpfr_t whose content is initialized and contains the estimate of
   the zero otherwise. */
static inline mpfr_t *uncertifiedFindZeros_handleInterval(mpfr_t x_left_bound, mpfr_t x_right_bound, mpfr_t y_left_bound, mpfr_t y_right_bound, node *f, node *diff_f, mpfr_t cutoff, mp_prec_t prec) {
  mpfr_t xl, xr, y;
  mpfr_t *temp;
  int sgn_left, sgn_right;
  int r;

  temp = NULL;
  if (mpfr_zero_p(y_right_bound)) {
    temp = safeMalloc(sizeof(mpfr_t));
    mpfr_init2(*temp, prec);
    mpfr_set(*temp, x_right_bound, GMP_RNDN);
    return temp;
  }
  if (mpfr_zero_p(y_left_bound)) {
    return NULL; /* We assume no other zero in the interval. x_left_bound will be added at next step */
  }

  /* y_*_bound might be a regular number, NaN or Inf. The only problematic case
     is when one of them is NaN (which is now equivalent to the fact that
     mpfr_sgn returns 0) */
  if (mpfr_sgn(y_left_bound) * mpfr_sgn(y_right_bound) < 0) {
    temp = safeMalloc(sizeof(mpfr_t));
    mpfr_init2(*temp, prec);
    newton(*temp, f, diff_f, x_left_bound, x_right_bound, mpfr_sgn(y_left_bound), prec);
    return temp;
  }
  if (mpfr_sgn(y_left_bound) * mpfr_sgn(y_right_bound) > 0) {
    return NULL;
  }

  /* f does not evaluate to a number at at least one bound. Maybe L'Hospital
     rule did not work, even though the function is well defined at the
     bounds.
     We try on an interval [xl,xr] slightly tighter that [x_left_bound, x_right_bound] */
  mpfr_init2(xl, prec);
  mpfr_init2(xr, prec);
  mpfr_init2(y, prec);

  mpfr_set(xl, x_left_bound, GMP_RNDU); /* exact */
  if(mpfr_zero_p(xl)) {
    mpfr_set_ui(xl, 1, GMP_RNDN);
    mpfr_div_2ui(xl, xl, 2*prec, GMP_RNDU);
  }
  else mpfr_nextabove(xl);

  mpfr_set(xr, x_right_bound, GMP_RNDD); /* exact */
  if(mpfr_zero_p(xr)) {
    mpfr_set_si(xr, -1, GMP_RNDN);
    mpfr_div_2ui(xr, xr, 2*prec, GMP_RNDD);
  }
  else mpfr_nextbelow(xr);

  if (mpfr_cmp(xl,xr)>0) {
    /* [x_left_bound, x_right_bound] is just an ulp. We give up. */
    mpfr_clear(xl);
    mpfr_clear(xr);
    mpfr_clear(y);
    return NULL;
  }

  sgn_left = mpfr_sgn(y_left_bound);
  if (sgn_left == 0) {
    r = evaluateFaithfulWithCutOffFast(y, f, diff_f, xl, cutoff, prec);
    if ( (r==0) || mpfr_zero_p(y) ) {
      temp = safeMalloc(sizeof(mpfr_t));
      mpfr_init2(*temp, prec);
      mpfr_set(*temp, xl, GMP_RNDN);
      mpfr_clear(xl);
      mpfr_clear(xr);
      mpfr_clear(y);
      return temp;
    }
    else sgn_left = mpfr_sgn(y);
  }

  sgn_right = mpfr_sgn(y_right_bound);
  if (sgn_right == 0) {
    r = evaluateFaithfulWithCutOffFast(y, f, diff_f, xr, cutoff, prec);
    if ( (r==0) || mpfr_zero_p(y) ) {
      temp = safeMalloc(sizeof(mpfr_t));
      mpfr_init2(*temp, prec);
      mpfr_set(*temp, xr, GMP_RNDN);
      mpfr_clear(xl);
      mpfr_clear(xr);
      mpfr_clear(y);
      return temp;
    }
    else sgn_right = mpfr_sgn(y);
  }

  temp = NULL;
  if (sgn_left*sgn_right<0) {
    temp = safeMalloc(sizeof(mpfr_t));
    mpfr_init2(*temp, prec);
    newton(*temp, f, diff_f, xl, xr, sgn_left, prec);
  }

  mpfr_clear(xl);
  mpfr_clear(xr);
  mpfr_clear(y);
  return temp;
}


/* Finds the zeros of a function on an interval. */
chain *uncertifiedFindZeros(node *tree, mpfr_t a, mpfr_t b, unsigned long int points, mp_prec_t prec) {
  mpfr_t cutoff, h;
  enhanced_mpfr_t x[3];
  mpfr_t y[3];
  mpfr_t *temp;
  node *diff_tree;
  chain *result=NULL;
  int k;
  int r;
  int left_bound = -1;
  int new_right_bound = -1;
  mp_prec_t prec_bounds = (mpfr_get_prec(a) > mpfr_get_prec(b)) ? mpfr_get_prec(a) : mpfr_get_prec(b);

  mpfr_init2(h,prec);
  mpfr_init2(cutoff,12);

  for(k=0;k<=2;k++) {
    enhanced_mpfr_init2(x[k], prec, prec_bounds);
    mpfr_init2(y[k], 5); /* Only the sign of this variable is required */
  }

  diff_tree = differentiate(tree);
  mpfr_set_si(cutoff, 0, GMP_RNDN);
  mpfr_sub(h,b,a,GMP_RNDD);  mpfr_div_si(h,h,points,GMP_RNDD);
  /* Little trick: if a=b, we set h to 1,
     thus x[0]=a=b and x[k] < a for k >= 1
     and we exit directly from the loop */
  if(mpfr_equal_p(a,b)) { mpfr_set_ui(h, 1, GMP_RNDN); }

  /* We go from right to left of [a, b]
     Loop invariant :
       x[2] < x[1] < x[0] <= b
       x[0] >= a
       for k=0..2, y[k] ~= f(x[k])
       the zeros of f on the interval (x[0], b] have already been investigated
       if y[0] is NaN, we have no way of discovering its possible value by looking at close points on its right
     We will process a sub-interval of the form [x[left_bound], x[0]], where y[left_bound] is not NaN, unless the point at its left itself evaluates to NaN.
     We determine 1 <= new_right_bound <= 2 such that, after handling the interval, we are left with [a, x[new_right_bound]].
     If x[new_right_bound] == a, we possibly add this bound to the list of zeros and exit.
  */
  x[0].i = INTERVAL_BOUND; mpfr_set(get_mpfr(x[0]), b, GMP_RNDN);
  r = evaluateFaithfulWithCutOffFast(y[0], tree, diff_tree, get_mpfr(x[0]), cutoff, prec);
  if (r==0) mpfr_set_d(y[0], 0, GMP_RNDN);
  for(k=1;k<=2;k++) {
    uncertifiedFindZeros_newpoint(&x[k], y[k], get_mpfr(x[k-1]), a, h, tree, diff_tree, cutoff, prec);
  }

  while(mpfr_cmp(a, get_mpfr(x[0])) < 0) {
    /* There are 5 possibilities:
        1)  NaN NaN y0 -> handle [x1, x0] then move left by 2 steps
        2)   y2 NaN y0 -> handle [x2, x0] then move left by 2 steps
        3)      y1  y0 -> handle [x1, x0] then move left by 1 step
        4)      NaN NaN -> move left by 1 step
        5)      y1  NaN -> handle [x1, x0] then move left by 1 step
    */
    new_right_bound = 1;
    if ( (!mpfr_nan_p(y[0])) && mpfr_nan_p(y[1]) ) {
      new_right_bound = 2;
    }

    left_bound = 1;
    if ( (!mpfr_nan_p(y[0])) && mpfr_nan_p(y[1]) && (!mpfr_nan_p(y[2])) ) {
      left_bound = 2;
    }

    if (! (mpfr_nan_p(y[0]) && mpfr_nan_p(y[1])) ) {
      temp = uncertifiedFindZeros_handleInterval(get_mpfr(x[left_bound]), get_mpfr(x[0]), y[left_bound], y[0], tree, diff_tree, cutoff, prec);
      if (temp != NULL) {
        result = addElement(result, temp);
      }
    }

    for(k=1;k<=new_right_bound;k++) {
      uncertfiedFindZeros_shift(x, y, a, h, tree, diff_tree, cutoff, prec);
    }
  }

  /* The whole interval (a, b] has been handled.
     Finally add the left bound of the interval when necessary */
  if (mpfr_equal_p(a, get_mpfr(x[0])) && mpfr_zero_p(y[0])) {
    temp = safeMalloc(sizeof(mpfr_t));
    mpfr_init2(*temp, mpfr_get_prec(get_mpfr(x[0])));
    mpfr_set(*temp, get_mpfr(x[0]), GMP_RNDN); /* exact */
    result = addElement(result, temp);
  }

  mpfr_clear(h);
  mpfr_clear(cutoff);

  for(k=0;k<=2;k++) {
    enhanced_mpfr_clear(x[k]);
    mpfr_clear(y[k]);
  }

  free_memory(diff_tree);

  return result;
}

/* Perform a step of exchange algorithm
   newx is the point to be inserted
   err_newx is the corresponding error
   lambdai_vect is the vector of lambda_i corresponding to vector x
   epsilon is the current radius of reference
   note that (p*w-f)(x_{n+1})= epsilon by definition
   and lambda_{n+1} = -1 by definition
   Thus the rule is
   * take the max of mu/lambda if sgn(err_newx)*sgn(epsilon)=-1
   * take the min otherwise
   n is the number of elements in x
*/
void single_step_remez(mpfr_t newx, mpfr_t err_newx, mpfr_t *x,
		       node **monomials_tree,
		       node *w,
		       mpfr_t *lambdai_vect,
		       mpfr_t epsilon,
		       int n, mp_prec_t prec) {
  int freeDegrees = n-1;
  int test,i,j,r, argmaxi, argmini;
  mpfr_t *N;
  mpfr_t *c;
  mpfr_t *mui_vect;
  node *temp_tree;
  node *temp_tree2;
  mpfr_t zero_mpfr, var1, var2, var3;
  mpfr_t maxi;
  mpfr_t mini;

  /* Initialisations and precomputations */
  mpfr_init2(var1, prec);
  mpfr_init2(var2, prec);
  mpfr_init2(var3, prec);

  mpfr_init2(zero_mpfr, 53);
  mpfr_set_d(zero_mpfr, 0., GMP_RNDN);

  mpfr_init2(maxi, prec);
  mpfr_init2(mini, prec);

  N = safeMalloc(freeDegrees*freeDegrees*sizeof(mpfr_t));
  c = safeMalloc(freeDegrees*sizeof(mpfr_t));
  mui_vect = safeMalloc(freeDegrees*sizeof(mpfr_t));

  /* Initialization of mui_vect */
  for(j=1; j <= freeDegrees ; j++) {
    for(i=1; i<= freeDegrees; i++) {
      mpfr_init2(N[coeff(i,j,freeDegrees)],prec);
    }
    mpfr_init2(c[j-1], prec);
    mpfr_init2(mui_vect[j-1], prec);
  }

  /* Computation of the matrix */
  for (i=1 ; i <= freeDegrees ; i++) {
    r = evaluateFaithfulWithCutOffFast(var1, w, NULL, x[i-1], zero_mpfr, prec);
    if(((r==1) || (r==4) || (r==5) || (r==6) || (r==7)) && (mpfr_number_p(var1))) test=1;
    else test=0;

    for (j=1 ; j <= freeDegrees ; j++) {
      if(test==1) {
	r = evaluateFaithfulWithCutOffFast(var2, monomials_tree[j-1], NULL, x[i-1], zero_mpfr, prec);
	if(((r==1) || (r==4) || (r==5) || (r==6) || (r==7)) && (mpfr_number_p(var2))) {
	  mpfr_mul(var2, var1, var2, GMP_RNDN);
	  mpfr_set(N[coeff(j,i,freeDegrees)],var2,GMP_RNDN);
	}
      }
      if((test==0) || (r==0) || (!mpfr_number_p(var2))) {
	temp_tree = allocateNode();
	temp_tree->nodeType = MUL;
	temp_tree->child1 = copyTree(monomials_tree[j-1]);
	temp_tree->child2 = copyTree(w);
	temp_tree = addMemRef(temp_tree);

	temp_tree2 = simplifyTreeErrorfree(temp_tree);
	free_memory(temp_tree);
	temp_tree = temp_tree2; /* temp_tree = g_j(x)*w(x) */

	r = evaluateFaithfulWithCutOffFast(var3, temp_tree, NULL, x[i-1], zero_mpfr, prec);

	if(r==0) mpfr_set_d(var3, 0., GMP_RNDN);
	mpfr_set(N[coeff(j,i,freeDegrees)],var3,GMP_RNDN);
	free_memory(temp_tree);
      }
    }
  }

  /* Computation of the vector corresponding to the new point */
  r = evaluateFaithfulWithCutOffFast(var1, w, NULL, newx, zero_mpfr, prec);
  if(((r==1) || (r==4) || (r==5) || (r==6) || (r==7)) && (mpfr_number_p(var1))) test=1;
  else test=0;

  for (j=1 ; j <= freeDegrees ; j++) {
    if(test==1) {
      r = evaluateFaithfulWithCutOffFast(var2, monomials_tree[j-1], NULL, newx, zero_mpfr, prec);
      if(((r==1) || (r==4) || (r==5) || (r==6) || (r==7)) && (mpfr_number_p(var2))) {
	mpfr_mul(var2, var1, var2, GMP_RNDN);
	mpfr_set(c[j-1],var2,GMP_RNDN);
      }
    }
    if((test==0) || (r==0) || (!mpfr_number_p(var2))) {
      temp_tree = allocateNode();
      temp_tree->nodeType = MUL;
      temp_tree->child1 = copyTree(monomials_tree[j-1]);
      temp_tree->child2 = copyTree(w);
      temp_tree = addMemRef(temp_tree);

      temp_tree2 = simplifyTreeErrorfree(temp_tree);
      free_memory(temp_tree);
      temp_tree = temp_tree2; /* temp_tree = g_j(x)*w(x) */

      r = evaluateFaithfulWithCutOffFast(var3, temp_tree, NULL, newx, zero_mpfr, prec);

      if(r==0) mpfr_set_d(var3, 0., GMP_RNDN);
      mpfr_set(c[j-1], var3, GMP_RNDN);
      free_memory(temp_tree);
    }
  }



  /* Resolution of the system */
  system_solve(mui_vect , N, c, freeDegrees, prec);

  /* Finding the maximum and minimum */
  mpfr_set(maxi, zero_mpfr, GMP_RNDN);
  argmaxi=freeDegrees;
  mpfr_set(mini, zero_mpfr, GMP_RNDN);
  argmini=freeDegrees;

  for(i=freeDegrees-1;i>=0;i--) {
    mpfr_div(var1, mui_vect[i], lambdai_vect[i], GMP_RNDN);
    if (mpfr_cmp(var1, maxi)>0) {
      mpfr_set(maxi, var1, GMP_RNDN);
      argmaxi=i;
    }
    if (mpfr_cmp(var1, mini)<0) {
      mpfr_set(mini, var1, GMP_RNDN);
      argmini=i;
    }
  }


  /* Introduce newx */
  if(mpfr_sgn(err_newx)*mpfr_sgn(epsilon)==1) {
    printMessage(4,SOLLYA_MSG_REMEZ_EXCHANGE_TAKE_A_CERTAIN_MINIMUM,"Remez: exchange algorithm takes the minimum (%.16v) at place %d\n",mini,argmini);
    mpfr_set(x[argmini], newx, GMP_RNDN);
  }
  else {
    printMessage(4,SOLLYA_MSG_REMEZ_EXCHANGE_TAKE_A_CERTAIN_MAXIMUM,"Remez: exchange algorithm takes the maximum (%.16v) at place %d\n",maxi,argmaxi);
    mpfr_set(x[argmaxi], newx, GMP_RNDN);
  }

  sollya_mpfr_sort(x, freeDegrees+1, prec);


  /* Freeing the memory */

  for(j=1; j <= freeDegrees ; j++) {
    for(i=1; i<= freeDegrees; i++) {
      mpfr_clear(N[coeff(i,j,freeDegrees)]);
    }
    mpfr_clear(c[j-1]);
    mpfr_clear(mui_vect[j-1]);
  }
  safeFree(N);
  safeFree(c);
  safeFree(mui_vect);

  mpfr_clear(zero_mpfr);
  mpfr_clear(var1);
  mpfr_clear(var2);
  mpfr_clear(var3);
  mpfr_clear(maxi);
  mpfr_clear(mini);

  return;
}


/* Store in res the zeros of tree on [a;b]
   deg+1 indicates the number of zeros which we are expecting.
   error' = tree  and tree' = diff_tree
*/
void quickFindZeros(mpfr_t *res, mpfr_t *curr_points,
		    node *error, node *tree, node *diff_tree,
		    node **monomials_tree, node *w, mpfr_t *lambdai_vect, mpfr_t epsilon, int HaarCompliant,
		    int deg,
		    mpfr_t a, mpfr_t b, mp_prec_t prec) {
  long int n = 50*(deg+2);
  long int i=0;
  int tooManyOscillations = 0; /* This variable is used to ensure that the
                                  message "the function oscillates too much"
                                  is displayed only once */

  /* The variable test is used to check that the maximum (in absolute value)
     of the error will be inserted in the new list of points.
     If it is not the case, a step of the exchange algorithm is performed */
  int test=0;
  mpfr_t h, x1, x2, x, y1, y2, zero_mpfr, maxi, argmaxi, z, alpha1, alpha2, alpha;

  mpfr_init2(h,prec);
  mpfr_init2(y1,prec);
  mpfr_init2(y2,prec);
  mpfr_init2(x1,prec);
  mpfr_init2(x2,prec);
  mpfr_init2(x, prec);
  mpfr_init2(zero_mpfr,prec);
  mpfr_init2(z, prec);
  mpfr_init2(maxi, prec);
  mpfr_init2(argmaxi, prec);
  mpfr_init2(alpha1, 24);
  mpfr_init2(alpha2, 24);
  mpfr_init2(alpha, 24);

  mpfr_set_d(zero_mpfr, 0., GMP_RNDN);

  evaluateFaithfulWithCutOffFast(z, error, tree, a, zero_mpfr, prec);
  mpfr_set(maxi,z,GMP_RNDN);
  mpfr_set(argmaxi,a,GMP_RNDN);
  evaluateFaithfulWithCutOffFast(z, error, tree, b, zero_mpfr, prec);
  if (mpfr_cmpabs(z,maxi)>0) {
    mpfr_set(maxi,z,GMP_RNDN);
    mpfr_set(argmaxi,b,GMP_RNDN);
  }

  mpfr_sub(h,b,a,GMP_RNDD);
  mpfr_div_si(h,h,n,GMP_RNDD);

  mpfr_set(x1,a,GMP_RNDN);
  mpfr_add(x2,a,h,GMP_RNDN);

  evaluateFaithfulWithCutOffFast(y1, tree, diff_tree, x1, zero_mpfr, prec);
  evaluateFaithfulWithCutOffFast(alpha1, diff_tree, NULL, x1, zero_mpfr, prec);

  while(mpfr_lessequal_p(x2,b)) {
    evaluateFaithfulWithCutOffFast(y2, tree, diff_tree, x2, zero_mpfr, prec);
    evaluateFaithfulWithCutOffFast(alpha2, diff_tree, NULL, x2, zero_mpfr, prec);
    if( (mpfr_sgn(y1)==0) || (mpfr_sgn(y2)==0) || (mpfr_sgn(y1) != mpfr_sgn(y2))) {
      if (mpfr_sgn(y1)==0) {
	evaluateFaithfulWithCutOffFast(z, error, tree, x1, zero_mpfr, prec);
	if (mpfr_sgn(z)*mpfr_sgn(alpha1)<0) {
	  i++;
	  if(i>deg+2) {
	    if (!tooManyOscillations)
              printMessage(2,SOLLYA_MSG_REMEZ_FUNCTION_OSCILLATES_TOO_MUCH,
                           "Warning: the function oscillates too much. Nevertheless, we try to continue.\n");
            tooManyOscillations = 1;
          }
	  else mpfr_set(res[i-1], x1, GMP_RNDN);
	}
	if (mpfr_cmpabs(z,maxi)>0) {
	  if ( (i>deg+2)||(mpfr_sgn(z)*mpfr_sgn(alpha1)>=0) ) test=0;
	  else test=1;
	  mpfr_set(maxi,z,GMP_RNDN);
	  mpfr_set(argmaxi,x1,GMP_RNDN);
	}

	/* Attention when decommenting this code sequence again: the
	   printMessages in it have not (or partially) been converted
	   to the new style */
	/* if(mpfr_sgn(y2)==0) {
           evaluateFaithfulWithCutOffFast(z, error, tree, x2, zero_mpfr, prec);
           if (mpfr_sgn(z)*mpfr_sgn(alpha2)<0) {
           i++;
           if(i>deg+2)
           printMessage(2,"Warning: the function oscillates too much. Nevertheless, we try to continue.\n");
           else mpfr_set(res[i-1], x2, GMP_RNDN);
           }
           if (mpfr_cmpabs(z,maxi)>0) {
           if ( (i>deg+2)||(mpfr_sgn(z)*mpfr_sgn(alpha2)>=0) ) test=0;
           else test=1;
           mpfr_set(maxi,z,GMP_RNDN);
           mpfr_set(argmaxi,x2,GMP_RNDN);
           }
	   }
        */
      }
      else {
	if (mpfr_sgn(y2)==0) {
	  evaluateFaithfulWithCutOffFast(z, error, tree, x2, zero_mpfr, prec);
	  if (mpfr_sgn(z)*mpfr_sgn(alpha2)<0) {
	    i++;
	    if(i>deg+2) {
              if (!tooManyOscillations)
                printMessage(2,SOLLYA_MSG_REMEZ_FUNCTION_OSCILLATES_TOO_MUCH,
                             "Warning: the function oscillates too much. Nevertheless, we try to continue.\n");
              tooManyOscillations = 1;
            }
	    else mpfr_set(res[i-1], x2, GMP_RNDN);
	  }
	  if (mpfr_cmpabs(z,maxi)>0) {
	    if ( (i>deg+2) || (mpfr_sgn(z)*mpfr_sgn(alpha2)>=0) ) test=0;
	    else test=1;
	    mpfr_set(maxi,z,GMP_RNDN);
	    mpfr_set(argmaxi,x2,GMP_RNDN);
	  }
	}
	else {
	  newton(x, tree, diff_tree, x1, x2, mpfr_sgn(y1), prec);
	  evaluateFaithfulWithCutOffFast(z, error, tree, x , zero_mpfr, prec);
	  evaluateFaithfulWithCutOffFast(alpha, diff_tree, NULL, x , zero_mpfr, prec);
	  if (mpfr_sgn(z)*mpfr_sgn(alpha)<0) {
	    i++;
	    if(i>deg+2) {
              if (!tooManyOscillations)
                printMessage(2,SOLLYA_MSG_REMEZ_FUNCTION_OSCILLATES_TOO_MUCH,
                             "Warning: the function oscillates too much. Nevertheless, we try to continue.\n");
              tooManyOscillations = 1;
            }
	    else mpfr_set(res[i-1], x, GMP_RNDN);
	  }
	  if (mpfr_cmpabs(z,maxi)>0) {
	    if ( (i>deg+2) || (mpfr_sgn(z)*mpfr_sgn(alpha)>=0) ) test=0;
	    else test=1;
	    mpfr_set(maxi,z,GMP_RNDN);
	    mpfr_set(argmaxi,x,GMP_RNDN);
	  }
	}
      }
    }

    mpfr_set(x1,x2,GMP_RNDN);
    mpfr_add(x2,x2,h,GMP_RNDN);
    mpfr_set(y1,y2,GMP_RNDN);
  }

  if ((i<deg)||(i>deg+2)||(!HaarCompliant)||(!test)) {
    /* printMessage(2,"Warning: the function fails to oscillate enough.\n");
       printMessage(2,"Check Haar condition and/or increase precision.\n");
       *crash_report = -1; */
    test=0;
    printMessage(2, SOLLYA_MSG_REMEZ_PERFORMING_AN_EXCHANGE_STEP, "Performing an exchange step...\n");
    printMessage(4,SOLLYA_MSG_REMEZ_COMPUTED_INFNORM_IS_A_CERTAIN_VALUE,"Computed infinity norm : %v\nReached at point %v\n",maxi,argmaxi);
    for(i=0;i<deg+2;i++) mpfr_set(res[i], curr_points[i], GMP_RNDN);
    single_step_remez(argmaxi, maxi, res, monomials_tree, w, lambdai_vect, epsilon, deg+2, prec);
  }
  else {
    /* in this branch test=1 */
    if (i==deg) {
      mpfr_set(res[deg], a, GMP_RNDU);
      mpfr_set(res[deg+1], b, GMP_RNDD);
      sollya_mpfr_sort(res, deg+2, prec);
    }
    else {
      if (i==deg+1) {
	evaluateFaithfulWithCutOffFast(y1, error, tree, a, zero_mpfr, prec);
	evaluateFaithfulWithCutOffFast(y2, error, tree, res[0], zero_mpfr, prec);
	if (mpfr_sgn(y1)==mpfr_sgn(y2))  mpfr_set(res[deg+1], b, GMP_RNDD);
	else {
	  evaluateFaithfulWithCutOffFast(y1,  error, tree, b, zero_mpfr, prec);
	  evaluateFaithfulWithCutOffFast(y2,  error, tree, res[deg], zero_mpfr, prec);
	  if (mpfr_sgn(y1)==mpfr_sgn(y2))  mpfr_set(res[deg+1], a, GMP_RNDU);
	  else {
	    evaluateFaithfulWithCutOffFast(y1,  error, tree, a, zero_mpfr, prec);
	    evaluateFaithfulWithCutOffFast(y2,  error, tree, b, zero_mpfr, prec);
	    if (mpfr_cmpabs(y1,y2)>0) mpfr_set(res[deg+1], a, GMP_RNDU);
	    else mpfr_set(res[deg+1], b, GMP_RNDD);
	  }
	}
	sollya_mpfr_sort(res, deg+2, prec);
      }
    }
  }

  /* We enter here if and only if we had (i=deg or i=deg+1) && HaarCompliant && test
     in the first place. */
  if(test) {
    /* since we did not perform an exchange step,
       we have to check that the pseudo-alternating condition
       is fulfilled */

    test=1;
    for(i=0; (i<deg+2)&&test ;i++) {
      evaluateFaithfulWithCutOffFast(z, error, tree, res[i] , zero_mpfr, prec);
      if ( mpfr_sgn(z)*mpfr_sgn(lambdai_vect[i])*mpfr_sgn(epsilon) >= 0 ) test=0;
    }
    if(!test) {
      printMessage(2, SOLLYA_MSG_REMEZ_FAILED_TO_FIND_PSEUDOALTERNATING_POINTS, "Failed to find pseudo-alternating points. Performing an exchange step...\n");
      printMessage(4, SOLLYA_MSG_REMEZ_COMPUTED_INFNORM_IS_A_CERTAIN_VALUE, "Computed infinity norm : %v\nReached at point %v\n", maxi, argmaxi);
      for(i=0;i<deg+2;i++) mpfr_set(res[i], curr_points[i], GMP_RNDN);
      single_step_remez(argmaxi, maxi, res, monomials_tree, w, lambdai_vect, epsilon, deg+2, prec);
    }
  }

  mpfr_clear(h); mpfr_clear(x1); mpfr_clear(x2); mpfr_clear(x); mpfr_clear(y1); mpfr_clear(y2); mpfr_clear(zero_mpfr); mpfr_clear(z); mpfr_clear(maxi); mpfr_clear(argmaxi); mpfr_clear(alpha1); mpfr_clear(alpha2); mpfr_clear(alpha);
  return;
}




/* This function finds the local extrema of a the error function poly*w-f.
   It uses the derivative and the second derivative of these functions to
   search the zeros of (poly*w-f)' by Newton's algorithm
   It expects to find at least freeDegrees+1 alternates extrema and
   returns it as a result. An initial estimation of these points is given
   in the vector x.
   Moreover, the quality of the approximation
   (defined by abs(err_max)/abs(err_min) - 1 where err_min and err_max
   denote the minimal and maximal extrema in absolute value) is stored
   in computedQuality and the infinity norm is stored in infinityNorm
   if these parameters are non NULL.
*/
int qualityOfError(mpfr_t computedQuality, mpfr_t infinityNorm, mpfr_t *x,
		   node *poly, node *f, node *w,
		   node **monomials_tree, mpfr_t *lambdai_vect, mpfr_t epsilon, int HaarCompliant,
		   int freeDegrees, mpfr_t a, mpfr_t b, mp_prec_t prec) {
  node *error;
  node *temp1;
  node *error_diff;
  node *error_diff2;
  int test, i, r;
  int case1, case2, case2b, case3;
  int *s;
  mpfr_t *y;
  mpfr_t var_mpfr, dummy_mpfr, dummy_mpfr2, max_val, zero_mpfr;
  mpfr_t *z;

  int crash_report = 0;
  int n = freeDegrees+1;

  mpfr_init2(var_mpfr, prec);
  mpfr_init2(zero_mpfr, 53);
  mpfr_init2(max_val, prec);
  mpfr_init2(dummy_mpfr, 5);
  mpfr_init2(dummy_mpfr2, 53);

  mpfr_set_d(zero_mpfr, 0., GMP_RNDN);

  z = safeMalloc(n*sizeof(mpfr_t));
  for(i=1;i<=n;i++) mpfr_init2(z[i-1],prec);


  /* Construction of the trees corresponding to (poly*w-f)' and (poly*w-f)'' */
  printMessage(8,SOLLYA_MSG_REMEZ_CONSTRUCTING_THE_ERROR_TREE,"Constructing the error tree...\n");
  error = allocateNode();
  error->nodeType = SUB;
  temp1 = allocateNode();
  temp1->nodeType = MUL;
  temp1->child1 = copyTree(poly);
  temp1->child2 = copyTree(w);
  error->child1 = addMemRef(temp1);
  error->child2 = copyTree(f);
  error = addMemRef(error);

  temp1 = simplifyTreeErrorfree(error);
  free_memory(error);
  error = temp1;

  printMessage(8,SOLLYA_MSG_REMEZ_CONSTRUCTING_THE_ERROR_PRIME_TREE,"Constructing the error' tree...\n");
  error_diff = differentiate(error);
  temp1 = simplifyTreeErrorfree(error_diff);
  free_memory(error_diff);
  error_diff = temp1;

  printMessage(8,SOLLYA_MSG_REMEZ_CONSTRUCTING_THE_ERROR_SECOND_TREE,"Constructing the error'' tree...\n");
  error_diff2 = differentiate(error_diff);
  temp1 = simplifyTreeErrorfree(error_diff2);
  free_memory(error_diff2);
  error_diff2 = temp1;

  printMessage(6, SOLLYA_MSG_REMEZ_COMPUTING_THE_YI, "Computing the yi...\n");
  /* If x = [x1 ... xn], we construct [y0 y1 ... yn] by
     y0 = (a+x1)/2, yn = (xn+b)/2 and yi = (xi + x(i+1))/2
  */
  y = (mpfr_t *)safeMalloc((n+1)*sizeof(mpfr_t));
  mpfr_init2(y[0], prec);
  mpfr_add(y[0], x[0], a, GMP_RNDN);
  mpfr_div_2ui(y[0], y[0], 1, GMP_RNDN);

  for(i=1; i<n; i++) {
    mpfr_init2(y[i], prec);
    mpfr_add(y[i], x[i-1], x[i], GMP_RNDN);
    mpfr_div_2ui(y[i], y[i], 1, GMP_RNDN);
  }

  mpfr_init2(y[n], prec);
  mpfr_add(y[n], x[n-1], b, GMP_RNDN);
  mpfr_div_2ui(y[n], y[n], 1, GMP_RNDN);

  printMessage(6,SOLLYA_MSG_REMEZ_THE_COMPUTED_YI_ARE_CERTAIN_VALUES,"The computed yi are: ");
  for (i=0;i<=n;i++) printMessage(6,SOLLYA_MSG_CONTINUATION,"%v ",y[i]);
  printMessage(6,SOLLYA_MSG_CONTINUATION,"\n");

  /* We call *case 1* the case where x1=a and xn=b
     We call *case 2* the case where x1<>a and xn=b
     and *case 2bis* the symetrical case
     We call *case 3* the case where x1<>a and xn<>b
  */

  if (mpfr_equal_p(y[0], a) &&  mpfr_equal_p(y[n],b)) {
    case1 = 1; case2 = 0; case2b = 0; case3 = 0;
  }
  else {
    if ((! mpfr_equal_p(y[0], a)) &&  mpfr_equal_p(y[n],b)) {
      case1 = 0; case2 = 1; case2b = 0; case3 = 0;
    }
    else {
      if (mpfr_equal_p(y[0], a) &&  (! mpfr_equal_p(y[n],b))) {
	case1 = 0; case2 = 0; case2b = 1; case3 = 0;
      }
      else {
	case1 = 0; case2 = 0; case2b = 0; case3 = 1;
      }
    }
  }

  printMessage(6, SOLLYA_MSG_REMEZ_ALGORITHM_IS_IN_A_CERTAIN_CASE, "We are in case %s\n", (case1 ? "1" : (case2 ? "2" : (case2b ? "2bis" : (case3 ? "3" : "unknown")))));

  /* If one of error_diff(y0) .... error_diff(yn) is a real NaN
     (i.e. if evaluateFaithfulWithCutOffFast returns 1 and store a NaN)
     this leads to numerical problems -> we use quickFindZeros

     If sgn(error_diff(yi))*sgn(error_diff(y(i+1))) > 0 for some i=1..n-2
     If we are in case 2 and sgn(error_diff(y0))*sgn(error_diff(y1)) > 0
     If we are in case 2bis and sgn(error_diff(y(n-1)))*sgn(error_diff(yn)) > 0
     If we are in case 3 and one of this two last condition is not fulfilled
     this means the hypothesis (xi ~ zeros of error_diff) is false -> quickFindZeros

     If we are in case 1 : if sgn(error_diff(y0))*sgn(error_diff(y1)) > 0 (the most probable)
     we have a problem if error(y0) is a real NaN or if sgn(error(y0))*sgn(error_diff(y0))>0
     if sgn(error_diff(y(n-1)))*sgn(error_diff(yn)) > 0 (the most probable)
     we have a problem if error(yn) is a real NaN or if sgn(error(yn))*sgn(error_diff(yn))<0

     If we are in case 2 if sgn(error_diff(y(n-1)))*sgn(error_diff(yn)) > 0 (the most probable)
     we have a problem if error(yn) is a real NaN or if sgn(error(yn))*sgn(error_diff(yn))<0

     If we are in case 2bis, if sgn(error_diff(y0))*sgn(error_diff(y1)) > 0 (the most probable)
     we have a problem if error(y0) is a real NaN or if sgn(error(y0))*sgn(error_diff(y0))>0
  */

  s = (int *)safeMalloc((n+1)*sizeof(int));
  test = 1;
  i = 0;
  while(test && (i<=n)) {
    r = evaluateFaithfulWithCutOffFast(dummy_mpfr, error_diff, error_diff2, y[i], zero_mpfr, prec);
    if((!mpfr_number_p(dummy_mpfr)) && ((r==1) || (r==4) || (r==5) || (r==6) || (r==7))) test=0;
    else {
      if(r==0) s[i]=0;
      else s[i] = mpfr_sgn(dummy_mpfr);
    }
    i++;
  }

  if (test) {
    printMessage(6,SOLLYA_MSG_REMEZ_THE_COMPUTED_SIGNS_ARE_CERTAIN_VALUES,"The computed signs are: ");
    for(i=0;i<=n;i++) printMessage(6,SOLLYA_MSG_CONTINUATION,"%d ",s[i]);
    printMessage(6,SOLLYA_MSG_CONTINUATION,"\n");
  } else {
    printMessage(6,SOLLYA_MSG_REMEZ_SIGNS_COULD_NOT_BE_EVALUATED,"Test is false because signs could not be evaluated\n");
  }

  if(test) {
    i = 1;
    while(test && (i<=n-2)) {
      if(s[i]*s[i+1] > 0) test=0;
      i++;
    }
  }
  if(test && case2 && (s[0]*s[1]>0)) test=0;
  if(test && case2b && (s[n-1]*s[n]>0)) test=0;
  if(test && case3 && ((s[0]*s[1]>0) || (s[n-1]*s[n]>0))) test=0;

  if(test && (case1 || case2b) && (s[0]*s[1]>0)) {
    r = evaluateFaithfulWithCutOffFast(dummy_mpfr, error, error_diff, y[0], zero_mpfr, prec);
    if((!mpfr_number_p(dummy_mpfr)) && ((r==1) || (r==4) || (r==5) || (r==6) || (r==7))) test=0;
    else {
      if((r!=0) && (mpfr_sgn(dummy_mpfr)*s[0] > 0)) test=0;
    }
  }

  if(test && (case1 || case2) && (s[n-1]*s[n]>0)) {
    r = evaluateFaithfulWithCutOffFast(dummy_mpfr, error, error_diff, y[n], zero_mpfr, prec);
    if((!mpfr_number_p(dummy_mpfr)) && ((r==1) || (r==4) || (r==5) || (r==6) || (r==7))) test=0;
    else {
      if((r!=0) && (mpfr_sgn(dummy_mpfr)*s[n] < 0)) test=0;
    }
  }

  if(test && HaarCompliant) {
    if((case1 || case2b) && (s[0]*s[1]<=0)) {
      if(s[0]==0) mpfr_set(z[0], a, GMP_RNDU);
      else {
	if(s[1]==0) mpfr_set(z[0], y[1], GMP_RNDN);
	else findZero(z[0], error_diff, error_diff2,y[0],y[1],s[0],NULL, NEWTON_STEPS,prec);
      }
    }
    if((case1 || case2b) && (s[0]*s[1]>0)) mpfr_set(z[0], a, GMP_RNDU);
    if(case2 || case3) findZero(z[0], error_diff, error_diff2, y[0], y[1], s[0], &x[0], NEWTON_STEPS, prec);

    for(i=1;i<=n-2;i++) findZero(z[i], error_diff, error_diff2, y[i], y[i+1], s[i], &x[i], NEWTON_STEPS, prec);

    if((case1 || case2) && (s[n-1]*s[n]<=0)) {
      if(s[n]==0) mpfr_set(z[n-1], b, GMP_RNDD);
      else {
	if(s[n-1]==0) mpfr_set(z[n-1], y[n-1], GMP_RNDN);
	else findZero(z[n-1], error_diff, error_diff2, y[n-1], y[n], s[n-1], NULL, NEWTON_STEPS, prec);
      }
    }

    if((case1 || case2) && (s[n-1]*s[n]>0)) mpfr_set(z[n-1],b,GMP_RNDD);
    if(case2b || case3) findZero(z[n-1], error_diff, error_diff2, y[n-1], y[n], s[n-1], &x[n-1], NEWTON_STEPS, prec);



    /* We expect error(z[i]) ~ - sgn(lambda[i])*epsilon
       We check the sign of error at these points and for z[i]<>a,b, we check the sign of error''
    */
    test=1;
    for(i=1; (i<=n) && test; i++) {
      r = evaluateFaithfulWithCutOffFast(var_mpfr, error, error_diff, z[i-1], zero_mpfr, prec);
      if(r==0) mpfr_set_d(var_mpfr, 0., GMP_RNDN);

      if ( mpfr_sgn(var_mpfr)*mpfr_sgn(lambdai_vect[i-1])*mpfr_sgn(epsilon) >= 0 ) test=0;

      if ( (!mpfr_equal_p(z[i-1],a)) && (!mpfr_equal_p(z[i-1],b)) ) {
	r = evaluateFaithfulWithCutOffFast(var_mpfr, error_diff2, NULL, z[i-1], zero_mpfr, prec);
	if(r==0) mpfr_set_d(var_mpfr, 0., GMP_RNDN);

	if(-mpfr_sgn(var_mpfr)*mpfr_sgn(epsilon)*mpfr_sgn(lambdai_vect[i-1]) >= 0) test=0;
      }
    }

    if (!test) {
      printMessage(2,SOLLYA_MSG_REMEZ_MAIN_HEURISTIC_FAILED_USING_SLOWER_ALGO,"Warning in Remez: main heuristic failed. A slower algorithm is used for this step.\n");
      quickFindZeros(z, x, error, error_diff, error_diff2, monomials_tree, w, lambdai_vect, epsilon, HaarCompliant, freeDegrees-1, a, b, prec);

      if(crash_report==-1) {
	free_memory(error);
	free_memory(error_diff);
	free_memory(error_diff2);
	mpfr_clear(var_mpfr);
	mpfr_clear(zero_mpfr);
	mpfr_clear(dummy_mpfr);
	mpfr_clear(dummy_mpfr2);
	mpfr_clear(max_val);
	safeFree(s);

	for(i=0;i<=n;i++)  mpfr_clear(y[i]);
	safeFree(y);
	for(i=1;i<=n;i++) {
	  mpfr_clear(z[i-1]);
	}
	safeFree(z);

	return -1;
      }
    }
  }
  else {
    printMessage(2, SOLLYA_MSG_REMEZ_SLOWER_ALGORITHM_USED_FOR_A_STEP, "Warning in Remez: a slower algorithm is used for this step%s\n", ((!HaarCompliant) ? " (pseudo-alternation condition changed)" : ""));

    quickFindZeros(z, x, error, error_diff, error_diff2, monomials_tree, w, lambdai_vect, epsilon, HaarCompliant, freeDegrees-1, a, b, prec);

    if(crash_report==-1) {
      free_memory(error);
      free_memory(error_diff);
      free_memory(error_diff2);
      mpfr_clear(var_mpfr);
      mpfr_clear(zero_mpfr);
      mpfr_clear(dummy_mpfr);
      mpfr_clear(dummy_mpfr2);
      mpfr_clear(max_val);
      safeFree(s);

      for(i=0;i<=n;i++)  mpfr_clear(y[i]);
      safeFree(y);
      for(i=1;i<=n;i++) {
	mpfr_clear(z[i-1]);
      }
      safeFree(z);

      return -1;
    }
  }

  printMessage(4,SOLLYA_MSG_REMEZ_THE_NEW_POINTS_ARE_CERTAIN_VALUES,"The new points are: ");
  for(i=1; i<=n; i++) printMessage(4,SOLLYA_MSG_CONTINUATION,"%v ",z[i-1]);
  printMessage(4,SOLLYA_MSG_CONTINUATION,"\n");

  /* Test the quality of the current error */

  mpfr_set_d(max_val, 0., GMP_RNDN);

  if((computedQuality!=NULL) || (infinityNorm != NULL)) {
    for(i=1;i<=n;i++) {
      r = evaluateFaithfulWithCutOffFast(var_mpfr, error, error_diff, z[i-1], zero_mpfr, prec);
      if(r==0) mpfr_set_d(var_mpfr, 0., GMP_RNDN);

      mpfr_abs(var_mpfr, var_mpfr, GMP_RNDN);
      if(mpfr_cmp(var_mpfr, max_val) > 0) mpfr_set(max_val, var_mpfr, GMP_RNDU);
    }

    mpfr_div(var_mpfr, max_val, epsilon, (mpfr_cmp_ui(epsilon,0)>0)?GMP_RNDU:GMP_RNDD);
    mpfr_abs(var_mpfr, var_mpfr, GMP_RNDU);
    mpfr_sub_ui(var_mpfr, var_mpfr, 1, GMP_RNDU);
  }

  if(computedQuality!=NULL) mpfr_set(computedQuality, var_mpfr, GMP_RNDU);
  if(infinityNorm!=NULL) mpfr_set(infinityNorm, max_val, GMP_RNDU);

  printMessage(2, SOLLYA_MSG_REMEZ_THE_CURRENT_NORM_TAKES_A_CERTAIN_VALUE, "Current norm: %v (1 +/- %.3v)\n",max_val,var_mpfr);

  free_memory(error);
  free_memory(error_diff);
  free_memory(error_diff2);
  mpfr_clear(var_mpfr);
  mpfr_clear(zero_mpfr);
  mpfr_clear(dummy_mpfr);
  mpfr_clear(dummy_mpfr2);
  mpfr_clear(max_val);
  safeFree(s);

  for(i=0;i<=n;i++)  mpfr_clear(y[i]);
  safeFree(y);
  for(i=1;i<=n;i++) {
    mpfr_set(x[i-1], z[i-1], GMP_RNDN);
    mpfr_clear(z[i-1]);
  }
  safeFree(z);

  return 0;
}

/* x being an array of n points, randomly perturbs the points of the
   array. More precisely, for each i in [1,n-2], using the notations below and
   noting d=min(d1,d2), x[i] is replaced by x[i] + s where s belongs to
   [-d,d]/2^k.

    x[i-1]      x[i]                  x[i+1]
       |----------|---------------------|
        <-- d1 --> <-------- d2 ------->

     For the point x[0], s belongs to [0, d2]/2^k, and and for the point x[n-1],
     s belongs to [-d1, 0]/2^k, but only if perturb_bounds evaluates to
     true. If it evaluates to false, x[0] and x[n-1] are not perturbed. */
void perturbPoints(mpfr_t *x, int n, int k, int perturb_bounds, mp_prec_t prec) {
  gmp_randstate_t random_state;
  mpfr_t s, d1, d2;
  int i;

  gmp_randinit_default(random_state);
  gmp_randseed_ui(random_state, 65845285);


  /* Random pertubration of the points... */
  mpfr_init2(d1, prec);
  mpfr_init2(d2, prec);
  mpfr_init2(s, prec);

  for(i=0;i<=n-1;i++) {
    if (perturb_bounds || ((i>0) && (i<n-1)))
      mpfr_urandomb(s, random_state);
    else
      mpfr_set_ui(s, 0, GMP_RNDN);

    if ((i>=1) && (i<=n-2)) {
      mpfr_mul_2ui(s, s, 1, GMP_RNDN);
      mpfr_sub_ui(s, s, 1, GMP_RNDN);
    }
    else if (i==n-1) {
      mpfr_mul_si(s, s, -1, GMP_RNDN);
    }
    mpfr_div_2ui(s, s, k, GMP_RNDN); /* s in {[-1,1] or [-1,0] or [0,1]}/2^k */

    if (i>0) mpfr_sub(d1, x[i], x[i-1], GMP_RNDN);
    else mpfr_set_inf(d1, 1);

    if (i<n-1) mpfr_sub(d2, x[i+1], x[i], GMP_RNDN);
    else mpfr_set_inf(d2, 1);

    if (mpfr_cmpabs(d1,d2)>0) mpfr_mul(s, d2, s, GMP_RNDN);
    else mpfr_mul(s, d1, s, GMP_RNDN);

    mpfr_add(x[i], x[i], s, GMP_RNDN);
  }

  mpfr_clear(d1);
  mpfr_clear(d2);
  mpfr_clear(s);
  gmp_randclear(random_state);
}

/*
  Normally, we have satisfying_error < target_error.
  If we manage to prove that target_error is unreachable, we stop the algorithm, returning error.
  If we manage to reach satisfying_error, we stop the algorithm, returning the current polynomial.
  Otherwise, we run the algorithm until the required quality is obtained.

  -----------------------|----------------------------|-------------------------->
                      satisfying                     target
          :-)                                                       :-(

*/
node *remezAux(node *f, node *w, chain *monomials, mpfr_t u, mpfr_t v, mp_prec_t prec, mpfr_t quality, mpfr_t satisfying_error, mpfr_t target_error) {
  int freeDegrees = lengthChain(monomials);
  int i, j, r, count, test, crash, HaarCompliant, forEverNotHaarCompliant;
  mpfr_t zero_mpfr, var1, var2, var3, computedQuality, infinityNorm;
  node *temp_tree;
  node *temp_tree2;
  node *temp_tree_simplified;
  node *poly;
  node *res;
  chain *curr;
  node **monomials_tree;
  mpfr_t *x;
  mpfr_t *M;
  mpfr_t *N;
  mpfr_t *b;
  mpfr_t *c;
  mpfr_t *ai_vect;
  mpfr_t *lambdai_vect;
  mpfr_t *previous_lambdai_vect;
  mpfr_t previous_epsilon;
  int quality_prec;
  int degenerated_warning_already_displayed = 0;

  /* Make compiler happy */
  res = NULL;
  /* End of compiler happiness */

  forEverNotHaarCompliant = 0;

  quality_prec = (mpfr_regular_p(quality)?(10 - mpfr_get_exp(quality)):prec);

  HaarCompliant=1;

  printMessage(3, SOLLYA_MSG_ENTERING_REMEZ_FUNCTION, "Entering in Remez function...\nRequired quality : %v\n",quality);

  /* Initialisations and precomputations */
  mpfr_init2(var1, prec);
  mpfr_init2(var2, prec);
  mpfr_init2(var3, prec);

  mpfr_init2(zero_mpfr, 53);
  mpfr_set_d(zero_mpfr, 0., GMP_RNDN);

  mpfr_init2(previous_epsilon, prec);
  mpfr_set(previous_epsilon, zero_mpfr, GMP_RNDN);

  if (mpfr_get_prec(quality)>prec) mpfr_init2(computedQuality, mpfr_get_prec(quality));
  else mpfr_init2(computedQuality, prec);

  mpfr_set_inf(computedQuality, 1);
  mpfr_init2(infinityNorm, quality_prec);

  M = safeMalloc((freeDegrees+1)*(freeDegrees+1)*sizeof(mpfr_t));
  N = safeMalloc(freeDegrees*freeDegrees*sizeof(mpfr_t));
  b = safeMalloc((freeDegrees+1)*sizeof(mpfr_t));
  c = safeMalloc(freeDegrees*sizeof(mpfr_t));
  ai_vect = safeMalloc((freeDegrees+1)*sizeof(mpfr_t));
  lambdai_vect = safeMalloc((freeDegrees+1)*sizeof(mpfr_t));
  previous_lambdai_vect = safeMalloc((freeDegrees+1)*sizeof(mpfr_t));
  x = safeMalloc((freeDegrees+1)*sizeof(mpfr_t));

  for(j=1; j <= freeDegrees+1 ; j++) {
    for(i=1; i<= freeDegrees+1; i++) {
      mpfr_init2(M[coeff(i,j,freeDegrees+1)],prec);
    }
    mpfr_init2(b[j-1], prec);
    mpfr_init2(ai_vect[j-1], prec);
    mpfr_init2(x[j-1], prec);
  }

  for(j=1; j <= freeDegrees ; j++) {
    for(i=1; i<= freeDegrees; i++) {
      mpfr_init2(N[coeff(i,j,freeDegrees)],prec);
    }
    mpfr_init2(c[j-1], prec);
    mpfr_init2(lambdai_vect[j-1], prec);
    mpfr_init2(previous_lambdai_vect[j-1], prec);
  }
  mpfr_init2(lambdai_vect[freeDegrees], prec);
  mpfr_init2(previous_lambdai_vect[freeDegrees], prec);
  mpfr_set_si(lambdai_vect[freeDegrees],-1,GMP_RNDN);
  mpfr_set_si(previous_lambdai_vect[freeDegrees],-1,GMP_RNDN);

  poly = NULL;
  printMessage(8, SOLLYA_MSG_REMEZ_COMPUTING_MONOMIALS, "Computing monomials...\n");
  pushTimeCounter();
  monomials_tree = safeMalloc(freeDegrees*sizeof(node *));
  curr = monomials;
  for(j=0;j<freeDegrees;j++) {
    monomials_tree[j] =  copyTree((node *)(curr->value));
    curr=curr->next;
  }
  popTimeCounter("Remez: computing monomials");


  count = 0;

  /* Definition of the array x of the n+2 Chebychev points */

  printMessage(8, SOLLYA_MSG_REMEZ_COMPUTING_INITIAL_POINT_SET, "Computing an initial points set...\n");
  pushTimeCounter();

  /*************************************************************/
  mpfr_const_pi(var1, GMP_RNDN);
  mpfr_div_si(var1, var1, (long)freeDegrees, GMP_RNDN); /* var1 = Pi/freeDegrees */
  mpfr_sub(var2, u, v, GMP_RNDN);
  mpfr_div_2ui(var2, var2, 1, GMP_RNDN); /* var2 = (u-v)/2 */
  mpfr_add(var3, u, v, GMP_RNDN);
  mpfr_div_2ui(var3, var3, 1, GMP_RNDN); /* var3 = (u+v)/2 */

  for (i=1 ; i <= freeDegrees+1 ; i++) {
    mpfr_mul_si(x[i-1], var1, i-1, GMP_RNDN);
    mpfr_cos(x[i-1], x[i-1], GMP_RNDN);
    mpfr_fma(x[i-1], x[i-1], var2, var3, GMP_RNDN); /* x_i = [cos((i-1)*Pi/freeDegrees)]*(u-v)/2 + (u+v)/2 */
  }
  mpfr_set(x[0], u, GMP_RNDU);
  mpfr_set(x[freeDegrees], v, GMP_RNDD);

  /* Random pertubration of the points... */
  perturbPoints(x, freeDegrees+1, 2, 0, prec);

  /*************************************************************/


  /*************************************************************/
  /*                  Manually chosen points                   */
  /*************************************************************/
  /* assume the list of points to be stored in variable list:
     run:   i=0; for t in list do {write("mpfr_set_str(x[",i,"],\"",t,"\", 10, GMP_RNDN);\n"); i=i+1;} ;
  */

  /*
    mpfr_set_str(x[0],"-0.3125e-1", 10, GMP_RNDN);
    mpfr_set_str(x[1],"-0.270866924296709954921192919457109841628145246303031e-1", 10, GMP_RNDN);
    mpfr_set_str(x[2],"-0.156792125481182037300460865714390558114871681447265e-1", 10, GMP_RNDN);
    mpfr_set_str(x[3],"0.270866923865259682207709736846537325622398567463872667e-1", 10, GMP_RNDN);
  */
  /*************************************************************/



  /*************************************************************/
  /*                 Evenly distributed points                 */
  /*************************************************************/
  /*
    mpfr_sub(var1, v, u, GMP_RNDN);
    mpfr_div_si(var1, var1, (long)(freeDegrees), GMP_RNDN); // var1 = (v-u)/freeDegrees
    for (i=1 ; i <= freeDegrees+1 ; i++) {
    mpfr_mul_si(x[i-1], var1, i-1, GMP_RNDN);
    mpfr_add(x[i-1], x[i-1], u, GMP_RNDN);
    }
  */
  /*************************************************************/


  /*************************************************************/
  /*                  Alternative Cheb points                  */
  /*************************************************************/
  /*
    mpfr_const_pi(var1, GMP_RNDN);
    mpfr_div_si(var1, var1, 2*((long)freeDegrees+1), GMP_RNDN); // var1 = Pi/(2*freeDegrees+2)
    mpfr_sub(var2, u, v, GMP_RNDN);
    mpfr_div_2ui(var2, var2, 1, GMP_RNDN); // var2 = (u-v)/2
    mpfr_add(var3, u, v, GMP_RNDN);
    mpfr_div_2ui(var3, var3, 1, GMP_RNDN); // var3 = (u+v)/2

    for (i=1 ; i <= freeDegrees+1 ; i++) {
    mpfr_mul_si(x[i-1], var1, 2*i-1, GMP_RNDN);
    mpfr_cos(x[i-1], x[i-1], GMP_RNDN);
    mpfr_fma(x[i-1], x[i-1], var2, var3, GMP_RNDN); // x_i=[cos((2i-1)*Pi/(2freeDegrees+2))]*(u-v)/2 + (u+v)/2
    }
  */
  /*************************************************************/

  popTimeCounter("Remez: computing initial points set");
  printMessage(4,SOLLYA_MSG_REMEZ_THE_COMPUTED_POINT_SET_IS_CERTAIN_VALUES,"Computed points set:\n");
  for(i=1;i<=freeDegrees+1;i++) printMessage(4,SOLLYA_MSG_CONTINUATION,"%v ",x[i-1]);
  printMessage(4,SOLLYA_MSG_CONTINUATION,"\n");

  mpfr_set_inf(infinityNorm, 1);
  mpfr_set_ui(ai_vect[freeDegrees], 0, GMP_RNDN);

  /* The parameter epsilon is stored in ai_vect[freeDegrees] */
  while( (mpfr_cmp(computedQuality, quality)>0)
         && (count<200)
         && (mpfr_cmpabs(ai_vect[freeDegrees],target_error)<=0)
         && (mpfr_cmp(infinityNorm,satisfying_error)>0)
         ) {
    while( (mpfr_cmp(computedQuality, quality)>0)
           && (count<200)
           && (mpfr_cmpabs(ai_vect[freeDegrees],target_error)<=0)
           && (mpfr_cmp(infinityNorm,satisfying_error)>0)
           ) {
      free_memory(poly);

      /* Definition of the matrices M and N of Remez algorithm
         N lets us determine the modified alternation property
         M lets us solve the interpolation problem
      */
      printMessage(4, SOLLYA_MSG_REMEZ_COMPUTING_THE_MATRIX, "Step %d\nComputing the matrix...\n",count);
      pushTimeCounter();

      for (i=1 ; i <= freeDegrees+1 ; i++) {
	r = evaluateFaithfulWithCutOffFast(var1, w, NULL, x[i-1], zero_mpfr, prec);
	if(((r==1) || (r==4) || (r==5) || (r==6) || (r==7)) && (mpfr_number_p(var1))) test=1;
	else test=0;

	for (j=1 ; j <= freeDegrees ; j++) {
	  if(test==1) {
	    r = evaluateFaithfulWithCutOffFast(var2, monomials_tree[j-1], NULL, x[i-1], zero_mpfr, prec);
	    if(((r==1) || (r==4) || (r==5) || (r==6) || (r==7)) && (mpfr_number_p(var2))) {
	      mpfr_mul(var2, var1, var2, GMP_RNDN);
	      mpfr_set(M[coeff(i,j,freeDegrees+1)],var2,GMP_RNDN);
	      if (i<=freeDegrees) mpfr_set(N[coeff(j,i,freeDegrees)],var2,GMP_RNDN);
	      else mpfr_set(c[j-1],var2,GMP_RNDN);
	    }
	  }
	  if((test==0) || (r==0) || (!mpfr_number_p(var2))) {
	    printMessage(2,SOLLYA_MSG_REMEZ_COMPUTAT_OF_MATRIX_ENTRY_USES_SLOWER_ALGO,"Information: the construction of M[%d,%d] uses a slower algorithm\n",i,j);
	    temp_tree = allocateNode();
	    temp_tree->nodeType = MUL;
	    temp_tree->child1 = copyTree(monomials_tree[j-1]);
	    temp_tree->child2 = copyTree(w);
	    temp_tree = addMemRef(temp_tree);

	    temp_tree2 = simplifyTreeErrorfree(temp_tree);
	    free_memory(temp_tree);
	    temp_tree = temp_tree2; /* temp_tree = x^(monomials[j])*w(x) */

	    r = evaluateFaithfulWithCutOffFast(var3, temp_tree, NULL, x[i-1], zero_mpfr, prec);

	    if(r==0) mpfr_set_d(var3, 0., GMP_RNDN);
	    mpfr_set(M[coeff(i,j,freeDegrees+1)],var3,GMP_RNDN);
	    if (i<=freeDegrees) mpfr_set(N[coeff(j,i,freeDegrees)],var3,GMP_RNDN);
	    else mpfr_set(c[j-1], var3, GMP_RNDN);
	    free_memory(temp_tree);
	  }
	}
      }

      system_solve( lambdai_vect , N, c, freeDegrees, prec);

      if(HaarCompliant==2) HaarCompliant=0; /* Too many oscillations: forcing exchange step */
      else {
	HaarCompliant=1;
	for(i=1; i<=freeDegrees+1; i++) {
	  if (mpfr_sgn(lambdai_vect[i-1])*mpfr_sgn(previous_lambdai_vect[i-1])<=0) HaarCompliant=0;
	}
	if(count==0) HaarCompliant=1;
      }
      if (forEverNotHaarCompliant) HaarCompliant = 0;

      for (i=1 ; i <= freeDegrees+1 ; i++) {
	if (mpfr_sgn(lambdai_vect[i-1])>0)
	  mpfr_set_si(M[coeff(i, freeDegrees+1, freeDegrees+1)], 1 ,GMP_RNDN);
	else {
	  if (mpfr_sgn(lambdai_vect[i-1])<0)
	    mpfr_set_si(M[coeff(i, freeDegrees+1, freeDegrees+1)], -1 ,GMP_RNDN);
	  else {
            if (!degenerated_warning_already_displayed) {
              degenerated_warning_already_displayed = 1;
              printMessage(1,SOLLYA_MSG_REMEZ_DEGENERATED_SYSTEM_IN_NON_HAAR_CONTEXT,"Warning: degenerated system in a non Haar context. The algorithm may be incorrect.\n");
            }
	    mpfr_set_si(M[coeff(i, freeDegrees+1, freeDegrees+1)], 1 ,GMP_RNDN);
	  }
	}
      }

      printMessage(4,SOLLYA_MSG_REMEZ_SIGNS_FOR_PSEUDO_ALTERN_ARE_CERTAIN_VALS,"Signs for pseudo-alternating condition : [");
      for (i=1 ; i <= freeDegrees ; i++) {
	printMessage(4,SOLLYA_MSG_CONTINUATION,"%.3v, ",M[coeff(i, freeDegrees+1, freeDegrees+1)]);
      }
      printMessage(4,SOLLYA_MSG_CONTINUATION,"-1]\n");

      popTimeCounter("Remez: computing the matrix");

      printMessage(7,SOLLYA_MSG_REMEZ_THE_COMPUTED_MATRIX_HAS_A_CERTAIN_VALUE,"The computed matrix is ");
      printMessageMatrix(7,M,freeDegrees+1);
      printMessage(7,SOLLYA_MSG_CONTINUATION,"\n");

      /* Determination of the polynomial corresponding to M and x */
      for (i=1 ; i <= freeDegrees+1 ; i++) {
	r = evaluateFaithfulWithCutOffFast(var1, f, NULL, x[i-1], zero_mpfr, prec); /* var1=f(x_i) */
	if(r==0) mpfr_set_d(var1, 0., GMP_RNDN);

	mpfr_set(b[i-1],var1,GMP_RNDN);
      }

      printMessage(8, SOLLYA_MSG_REMEZ_SOLVING_THE_SYSTEM, "Resolving the system...\n");

      pushTimeCounter();
      system_solve(ai_vect, M, b, freeDegrees+1, prec);
      popTimeCounter("Remez: solving the system");

      poly = constructPolynomialFromArray(ai_vect, monomials_tree, freeDegrees);

      printMessage(3, SOLLYA_MSG_REMEZ_THE_COMPUTED_POLY_HAS_A_CERTAIN_VALUE, "The computed polynomial is %b\n",poly);
      printMessage(2, SOLLYA_MSG_REMEZ_CURRENT_EPSILON_HAS_A_CERTAIN_VALUE, "Current value of epsilon : %.16v\n",ai_vect[freeDegrees]);

      /* Plotting the error curve */
      /*     node *plotTemp; */
      /*     chain *plotList=NULL; */
      /*     plotTemp = makeSub(makeMul(copyTree(poly),copyTree(w)),copyTree(f)); */
      /*     plotList=addElement(plotList, plotTemp); */
      /*     plotTree(plotList,u,v,defaultpoints,prec,NULL,0); */
      /*     free_memory(plotTemp); */
      /*    freeChain(plotList, nothing); */

      /* Computing the useful derivatives of functions */
      printMessage(8, SOLLYA_MSG_REMEZ_DIFFERENTIATING_THE_COMPUTED_POLYNOMIAL, "Differentiating the computed polynomial...\n");

      pushTimeCounter();

      /* Hornerization of the polynomial */
      /* temp_tree = horner(poly);
         free_memory(poly);
         poly = temp_tree;
      */

      printMessage(8, SOLLYA_MSG_REMEZ_SEARCHING_FOR_EXTREMA_OF_ERROR_FUNCTION, "Searching extrema of the error function...\n");

      /* Find extremas and tests the quality of the current approximation */
      pushTimeCounter();

      crash = qualityOfError(computedQuality, infinityNorm, x,
			     poly, f, w,
			     monomials_tree, lambdai_vect, ai_vect[freeDegrees], HaarCompliant,
			     freeDegrees, u, v, prec);
      popTimeCounter("Remez: computing the quality of approximation");

      if(crash==-1) {

	/* temporary check until I patch the algorithm in order to handle
	   correctly cases when the error oscillates too much
	*/
	temp_tree = addMemRef(makeSub(makeMul(copyTree(poly), copyTree(w)), copyTree(f)));
	uncertifiedInfnorm(infinityNorm, NULL, temp_tree, u, v, getToolPoints(), quality_prec);

	printMessage(2,SOLLYA_MSG_REMEZ_THE_BEST_POLY_GIVES_A_CERTAIN_ERROR,"The best polynomial obtained gives an error of %v\n",infinityNorm);

	free_memory(temp_tree);
	/* end of the temporary check */


	for(j=0;j<freeDegrees;j++) {
	  free_memory(monomials_tree[j]);
	}
	safeFree(monomials_tree);

	for(j=1;j<=freeDegrees+1;j++) mpfr_clear(x[j-1]);
	safeFree(x);

	mpfr_clear(zero_mpfr);
        mpfr_clear(previous_epsilon);
        mpfr_clear(var1);
	mpfr_clear(var2);
	mpfr_clear(var3);
	mpfr_clear(computedQuality);
	mpfr_clear(infinityNorm);

	for(j=1; j <= freeDegrees+1 ; j++) {
	  for(i=1; i<= freeDegrees+1; i++) {
	    mpfr_clear(M[coeff(i,j,freeDegrees+1)]);
	  }
	  mpfr_clear(b[j-1]);
	  mpfr_clear(ai_vect[j-1]);
	}
	safeFree(M);
	safeFree(b);
	safeFree(ai_vect);

	for(j=1; j <= freeDegrees ; j++) {
	  for(i=1; i<= freeDegrees; i++) {
	    mpfr_clear(N[coeff(i,j,freeDegrees)]);
	  }
	  mpfr_clear(c[j-1]);
	  mpfr_clear(lambdai_vect[j-1]);
	  mpfr_clear(previous_lambdai_vect[j-1]);
	}
	mpfr_clear(lambdai_vect[freeDegrees]);
	mpfr_clear(previous_lambdai_vect[freeDegrees]);
	safeFree(N);
	safeFree(c);
	safeFree(lambdai_vect);
	safeFree(previous_lambdai_vect);

	/* Christoph: replacing a recoverFromError with a construction
	   of the error special symbol and a return.  I am not 100%
	   sure that all memory has been freed at this point, as it
	   should be.
	*/
	return makeError();
      }

      printMessage(3, SOLLYA_MSG_REMEZ_CURRENT_QUALITY_HAS_A_CERTAIN_VALUE, "Current quality: %v\n",computedQuality);

      count++;
      for(i=1; i<=freeDegrees+1; i++) {
	mpfr_set(previous_lambdai_vect[i-1], lambdai_vect[i-1], GMP_RNDN);
      }

      if (mpfr_cmpabs(previous_epsilon, ai_vect[freeDegrees]) > 0) {
        forEverNotHaarCompliant = 1;
        printMessage(2, SOLLYA_MSG_REMEZ_SWITCHING_DEFINITIVELY_TO_SLOW_ALGORITHM, "Remez: multipoint algorithm failed due to lack of Haar condition. Switching back to single point algorithm.\n");
      }
      mpfr_set(previous_epsilon, ai_vect[freeDegrees], GMP_RNDN);
    }

    res = NULL;

    /* We check if exited the loop because we proved the target_error to be unreachable */
    /* If so, we exit returning error */
    if(mpfr_cmpabs(ai_vect[freeDegrees],target_error)>0) {
      printMessage(2, SOLLYA_MSG_REMEZ_FINISHES_AS_TARGET_ERROR_IS_NOT_REACHABLE, "Remez finished after %d steps\nThe target error (%.16v) has been proved unreachable.\n",count,target_error);
      printMessage(5, SOLLYA_MSG_CONTINUATION,"Last computed poly: %b\n",poly);

      res = copyTree(poly); /* Alternatively, we could do res = makeError(); */
    }

    if (!res) {
      /* temporary check until I patch the algorithm in order to handle
         correctly cases when the error oscillates too much
      */
      temp_tree = addMemRef(makeSub(addMemRef(makeMul(copyTree(poly), copyTree(w))), copyTree(f)));
      temp_tree_simplified = simplifyTreeErrorfree(temp_tree);
      free_memory(temp_tree);
      temp_tree = temp_tree_simplified;
      uncertifiedInfnorm(infinityNorm, &var1, temp_tree, u, v, getToolPoints(), quality_prec); /* var1 now contains a point where the max is reached */
      evaluateFaithfulWithCutOffFast(var2, temp_tree, NULL, var1, zero_mpfr, prec); /* var2 is the value of the error at a point where the norm is reached */
      free_memory(temp_tree);
      /* end of the temporary check */

      /* We check if we exited the loop because we managed to find a satisfying error */
      /* If so we exit returning the current polynomial */
      if (mpfr_cmp(infinityNorm,satisfying_error)<=0) {
	printMessage(2, SOLLYA_MSG_REMEZ_FINISHES_AS_TARGET_ERROR_HAS_BEEN_REACHED, "Remez finished after %d steps\nThe following satisfying error (%.16v) has been reached.\nCurrent infinity norm: %v\n",count,satisfying_error,infinityNorm);
        res = copyTree(poly);
      }
    }

    if (!res) {
      mpfr_div(computedQuality, infinityNorm, ai_vect[freeDegrees], (mpfr_cmp_ui(ai_vect[freeDegrees], 0)>0)?GMP_RNDU:GMP_RNDD);
      mpfr_abs(computedQuality, computedQuality, GMP_RNDU);
      mpfr_sub_ui(computedQuality, computedQuality, 1, GMP_RNDU);

      if(mpfr_cmp(computedQuality, quality)<=0) {
	printMessage(2, SOLLYA_MSG_REMEZ_FINISHES_AS_QUALITY_HAS_BEEN_REACHED, "Remez finished after %d steps\nThe computed infnorm is %.16v\nThe polynomial is optimal within a factor 1 +/- %.3v\n",count,infinityNorm,computedQuality);
	printMessage(5, SOLLYA_MSG_CONTINUATION, "Computed poly: %b\n",poly);
        res = copyTree(poly);
      }
    }

    if(res==NULL) {
      printMessage(2, SOLLYA_MSG_REMEZ_FAILS_AND_LOOPS_AGAIN, "Warning: Remez algorithm failed (too many oscillations?)\nLooping again\n");
      HaarCompliant=2;
      /* Attempt to (somehow) fix bug #8867: in case we forgot a point during the algorithm, we force its introduction now */
      single_step_remez(var1, var2, x, monomials_tree, w, lambdai_vect, ai_vect[freeDegrees], freeDegrees+1, prec);
    }
  }

  free_memory(poly);
  for(j=0;j<freeDegrees;j++) {
    free_memory(monomials_tree[j]);
  }
  safeFree(monomials_tree);

  for(i=1; i<=freeDegrees+1; i++) {
    mpfr_clear(x[i-1]);
  }
  safeFree(x);


  mpfr_clear(zero_mpfr);
  mpfr_clear(previous_epsilon);
  mpfr_clear(var1);
  mpfr_clear(var2);
  mpfr_clear(var3);

  for(j=1; j <= freeDegrees+1 ; j++) {
    for(i=1; i<= freeDegrees+1; i++) {
      mpfr_clear(M[coeff(i,j,freeDegrees+1)]);
    }
    mpfr_clear(b[j-1]);
    mpfr_clear(ai_vect[j-1]);
  }
  safeFree(M);
  safeFree(b);
  safeFree(ai_vect);

  for(j=1; j <= freeDegrees ; j++) {
    for(i=1; i<= freeDegrees; i++) {
      mpfr_clear(N[coeff(i,j,freeDegrees)]);
    }
    mpfr_clear(c[j-1]);
    mpfr_clear(lambdai_vect[j-1]);
    mpfr_clear(previous_lambdai_vect[j-1]);
  }
  mpfr_clear(lambdai_vect[freeDegrees]);
  mpfr_clear(previous_lambdai_vect[freeDegrees]);
  safeFree(N);
  safeFree(c);
  safeFree(lambdai_vect);
  safeFree(previous_lambdai_vect);

  mpfr_clear(computedQuality);
  mpfr_clear(infinityNorm);

  if (res == NULL) {
    printMessage(1, SOLLYA_MSG_REMEZ_DOES_NOT_CONVERGE, "Error in Remez: the algorithm does not converge.\n");
    res = makeError();
  }

  return res;
}

/* if tree is an expression of the form x^k, sets k in the address pointed to by i and returns 1. Otherwise returns 0 and let i unchanged */
int isPureMonomial(int *i, node *tree) {
  if (tree == NULL) return 0;
  if (isConstant(tree)) {
    *i = 0;
    return 1;
  }
  switch (tree->nodeType) {
  case MEMREF:
    return isPureMonomial(i, getMemRefChild(tree));
    break;
  case VARIABLE:
    *i = 1;
    return 1;
    break;
  case POW:
    if ( (accessThruMemRef(tree->child1)->nodeType == VARIABLE) &&
         evaluateThingToInteger(i, accessThruMemRef(tree->child2), NULL) ) {
      return 1;
    }
    else return 0;
    break;
  default:
    return 0;
  }
  return 0;
}

/* Test if a chain of monomial expressions only contains pure monomials (of the
   form x^i). If so, let n denotes the maximum degree of them; the function
   allocates an array T of n+1 int and sets it so that:
     T[i] equals -1 if x^i is not present in monomials
     T[i] equals k if x^i is monomials[k]
   Finally, we set n in the address pointed to by deg.
   If it does not contain only pure monomials, let deg unchanged and returns NULL.
*/
int *isPureListOfTrueMonomials(int *deg, chain *monomials) {
  chain *curr;
  int max = -1;
  int i;
  int index = 0;
  int test = 1;
  int *L;
  for(curr=monomials; curr!=NULL; curr=curr->next) {
    if (isPureMonomial(&i, curr->value)) {
      max = (max>i)?max:i;
    }
    else {
      test = 0;
    }
  }
  if (!test) return NULL;
  /* else... */
  L = (int *)safeCalloc(max+1 ,sizeof(int));
  for(i=0;i<max;i++) L[i] = -1;
  index = 0;
  for(curr=monomials; curr!=NULL; curr=curr->next) {
    isPureMonomial(&i, curr->value);
    L[i] = index;
    index++;
  }
  *deg = max;
  return L;
}

/* returns 1 if tree is provably the expression equal to 0 */
int isProvablyZero(node *tree) {
  sollya_mpfi_t y, x;
  int test;

  sollya_mpfi_init2(x, 64);
  sollya_mpfi_set_full_range(x);
  sollya_mpfi_init2(y, 64);
  evaluateInterval(y, tree, NULL, x);
  test = sollya_mpfi_is_zero(y);
  sollya_mpfi_clear(x);
  sollya_mpfi_clear(y);
  return test;
}

/* Returns 1 if f numerically evaluates to something very close to 0 on several points of [a,b] */
int seemsToBeZero(node *f, mpfr_t a, mpfr_t b) {
  gmp_randstate_t random_state;
  int p = 3; /* Number of points on which we evaluate the function */
  int i;
  mp_prec_t prec;
  mpfr_t x, y, tmp, zero_mpfr;
  int test = 1;
  int r;
  node *f_diff;

  gmp_randinit_default(random_state);
  gmp_randseed_ui(random_state, 65845285);

  f_diff = differentiate(f);

  prec = (mpfr_get_prec(a)>mpfr_get_prec(b))?mpfr_get_prec(a):mpfr_get_prec(b);
  prec = (prec>tools_precision)?prec:tools_precision;

  mpfr_init2(x, prec);
  mpfr_init2(y, prec);
  mpfr_init2(tmp, prec);
  mpfr_init2(zero_mpfr, 12);
  mpfr_set_ui(zero_mpfr, 0, GMP_RNDN);
  mpfr_sub(tmp, b, a, GMP_RNDD);
  for(i=0;i<p;i++) {
    /* Random point in [a,b] */
    mpfr_urandomb(x, random_state); /* in [0,1) */
    mpfr_mul(x, x, tmp, GMP_RNDN); /* in [0, b-a) */
    mpfr_add(x, x, a, GMP_RNDN); /* in [a,b) */
    r = evaluateFaithfulWithCutOffFast(y, f, f_diff, x, zero_mpfr, tools_precision);
    /* r=0 -> interval [-eps,eps] after increasing the precision -> practical 0
       r=1,4,6 -> faithful or correctly rounded result -> if result is 0, it is an exact 0 */
    if (! ( (r==0) ||
            ( ((r==1)||(r==4)||(r==6)) && mpfr_zero_p(y) )
            )) {
      test=0;
      break;
    }
  }
  mpfr_clear(x);
  mpfr_clear(y);
  mpfr_clear(tmp);
  mpfr_clear(zero_mpfr);
  free_memory(f_diff);
  gmp_randclear(random_state);
  return test;
}

/* Assuming that poly = sum a_i *gi(x), find a_i such that gi(x) = g(x) and store it as a constant expression in c */
/* Nothing is done for trying to recognize equivalent expressions: for
   instance, if g(x) = (x+1) and poly = 2*(1+x) the algorithm fails. The
   algorithm fails also if g(x) = (x+1) and poly = 2*(x+1)*3, whatever the way
   you put parentheses.  Returns 1 when it found a non trivial coefficient and
   0 otherwise. Notice that, in both cases, c is filled with a valid expression
   (the tree "0" in the case the function returns 0).
*/
int findCoeffInPseudoPolynomial(node **c, node *poly, node *g) {
  node *a, *b;
  node *temp;
  int r1, r2;

  if (poly == NULL)  return 0;
  switch (accessThruMemRef(poly)->nodeType) {
  case ADD:
    r1 = findCoeffInPseudoPolynomial(&a, accessThruMemRef(poly)->child1, g);
    r2 = findCoeffInPseudoPolynomial(&b, accessThruMemRef(poly)->child2, g);
    if (r1) {
      if (r2) *c = makeAdd(a,b);
      else { *c = a; free_memory(b); }
      return 1;
    }
    else {
      free_memory(a);
      if (r2) { *c = b; return 1; }
      free_memory(b);
    }
    break;
  case SUB:
    r1 = findCoeffInPseudoPolynomial(&a, accessThruMemRef(poly)->child1, g);
    r2 = findCoeffInPseudoPolynomial(&b, accessThruMemRef(poly)->child2, g);
    if (r1) {
      if (r2) *c = makeSub(a,b);
      else { *c = a; free_memory(b); }
      return 1;
    }
    else {
      free_memory(a);
      if (r2) { *c = makeNeg(b); return 1; }
      free_memory(b);
    }
    break;
  case NEG:
    r1 = findCoeffInPseudoPolynomial(&a, accessThruMemRef(poly)->child1, g);
    if (r1) { *c = makeNeg(a); return 1; }
    free_memory(a);
    break;
  case MUL:
    if ( isSyntacticallyEqual(accessThruMemRef(poly)->child2, g) && isConstant(accessThruMemRef(poly)->child1) ) {
      *c = copyTree(accessThruMemRef(poly)->child1); return 1;
    }
    if ( isSyntacticallyEqual(accessThruMemRef(poly)->child1, g) && isConstant(accessThruMemRef(poly)->child2) ) {
      *c = copyTree(accessThruMemRef(poly)->child2); return 1;
    }
    break;
  case DIV:
    if ( isSyntacticallyEqual(accessThruMemRef(poly)->child1, g) && isConstant(accessThruMemRef(poly)->child2) ) {
      *c = makeDiv(makeConstantDouble(1.0), copyTree(accessThruMemRef(poly)->child2)); return 1;
    }
    temp = makeDiv(makeConstantDouble(1.0), copyTree(accessThruMemRef(poly)->child2));
    if ( isSyntacticallyEqual(temp, g) && isConstant(accessThruMemRef(poly)->child1) ) {
      *c = copyTree(poly->child1);
      free_memory(temp); return 1;
    }
    free_memory(temp);
    break;
  }

  /* Nothing worked. Maybe, poly = g, in which case, the coefficient is implicitly 1,
     or poly = constant and g = constant, in which case the coefficient is implicitly poly/g,
     or poly = 0, in which case the coefficient is implicitly 0.  */
  if (isSyntacticallyEqual(poly, g)) { *c = makeConstantDouble(1.0); return 1; }

  if ( (isConstant(poly)) && (isConstant(g)) ) {
    *c = makeDiv(copyTree(poly), copyTree(g)); return 1;
  }

  /* Otherwise, we fail to recover the coeff: hence we set it to 0. */
  *c = makeConstantDouble(0.0);
  return 0;
}

/* Assuming that poly = sum a_i * monomials[i](x), this function tries to
   compute the array of the a_i and store it in coefficients. Enough room must
   be available in coefficients to store them all.
*/
void getCoefficientsInPseudoPolynomial(node **coefficients, node *poly, chain *monomials) {
  chain *curr;
  node *coeff;
  int i = 0;
  for (curr = monomials; curr != NULL; curr = curr->next) {
    findCoeffInPseudoPolynomial(&coeff, poly, (node *)(curr->value));
    coefficients[i] = coeff;
    i++;
  }
}

/* Heuristic to detect if a given tree is already a linear combination of
   monomials.  If monomials only contains true monomials (of the form x^i),
   returns true iff tree is provably a linear combination of them.  If
   monomials contains other kind of functions, returns true when it seems
   highly plausible that tree is a linear combination of them, based on several
   evaluations on the interval [a,b]. In the case it is a linear combination of
   the proper form, the coefficients are stored in coeffs. Enough room must be
   available in coeffs to store them all, and the mpfr_t must already be
   initialized.  BEWARE: if the tree is not a linear combination of monomials,
   some element of coeffs might nonetheless be modified by the function.
   Returns 1 in case of success and 0 in case of failure (in this case nothing
   can be said about the content of coefficients)
*/
int isTrivialRemezCase(node **coeffs, node *tree, chain *monomials, mpfr_t a, mpfr_t b) {
  int *L = NULL;
  int n;
  int i;
  int deg;
  int test = 1;
  node *temp_tree;

  if ( (isPolynomial(tree)) && (L = isPureListOfTrueMonomials(&n, monomials)) ) {
    test = 1;
    deg = getDegreeSilent(tree);
    if ( (deg < 0) || (deg > n)) test = 0;
    else {
      for(i=0;i<=n;i++) {
          temp_tree = getIthCoefficient(tree, i);
          if (L[i] != -1) {
            coeffs[L[i]] = temp_tree;
          }
          else {
            if (!isProvablyZero(temp_tree)) test = 0;
            free_memory(temp_tree);
          }
      }
    }
    safeFree(L);
  }
  else {
    getCoefficientsInPseudoPolynomial(coeffs, tree, monomials);
    temp_tree = makeSub(copyTree(tree), constructPolynomialFromExpressions(coeffs, monomials));
    test = seemsToBeZero(temp_tree, a, b);
    free_memory(temp_tree);
  }
  return test;
}

node *remez(node *func, node *weight, chain *monomials, mpfr_t a, mpfr_t b, mpfr_t quality, mpfr_t satisfying_error, mpfr_t target_error, mp_prec_t prec) {
  if (mpfr_equal_p(a,b))
    printMessage(1,SOLLYA_MSG_REMEZ_MAY_HAPPEN_NOT_TO_CONVRG_AS_DOM_IS_POINT,"Warning: the input interval is reduced to a single point. The algorithm may happen not to converge.\n");

  node **coeffs;
  int i,n;
  chain *curr;
  int test;

  node *temp = makeDiv(copyTree(func), copyTree(weight));
  node *temp_simplified = simplifyTreeErrorfree(temp);
  free_memory(temp);

  n = 0;
  for(curr=monomials;curr!=NULL; curr=curr->next) {
    n++;
  }
  coeffs = (node **)safeCalloc(n, sizeof(node *));

  /* If temp_simplified is a linear combination of monomials, then it is itself its best approximation. We could try to detect it in full generality, but for simplicity, for now, we only consider the case when monomials is a list of true monomials (of the form x^i) */
  test = isTrivialRemezCase(coeffs, temp_simplified, monomials, a, b);
  for(i=0;i<n;i++) {
    if (coeffs[i] != NULL) free_memory(coeffs[i]);
  }
  safeFree(coeffs);
  if (test) {
    printMessage(1, SOLLYA_MSG_REMEZ_IS_TRIVIAL, "Information (remez): the function to approximate is its own best approximation.\n");
    return temp_simplified;
  }
  else {
    free_memory(temp_simplified);
  }
  return remezAux(func, weight, monomials, a, b, prec, quality, satisfying_error, target_error);
}






node *constructPolynomialFromArray(mpfr_t *coeff, node **monomials_tree, int n) {
  int i;
  node *poly;

  poly = makeConstantDouble(0.0);
  for(i=0;i<n;i++) poly = makeAdd(makeMul(makeConstant(coeff[i]), copyTree(monomials_tree[i])),poly);

  return addMemRef(poly);
}


/* Construct a set of p Chebychev's points corresponding to the extrema
   of the Chebychev polynomial */
mpfr_t *chebychevsPoints(mpfr_t u, mpfr_t v, int p, mp_prec_t *currentPrec) {
  mpfr_t var1, var2, var3;
  mpfr_t *x;
  int i;
  mpfr_init2(var1, *currentPrec);
  mpfr_init2(var2, *currentPrec);
  mpfr_init2(var3, *currentPrec);

  x = (mpfr_t *)safeMalloc(p*sizeof(mpfr_t));

  mpfr_const_pi(var1, GMP_RNDN);
  mpfr_div_si(var1, var1, (long)(p-1), GMP_RNDN); /* var1 = Pi/(p-1) */
  mpfr_sub(var2, u, v, GMP_RNDN);
  mpfr_div_2ui(var2, var2, 1, GMP_RNDN); /* var2 = (u-v)/2 */
  mpfr_add(var3, u, v, GMP_RNDN);
  mpfr_div_2ui(var3, var3, 1, GMP_RNDN); /* var3 = (u+v)/2 */

  for (i=1 ; i <= p ; i++) {
    mpfr_init2(x[i-1], *currentPrec);
    mpfr_mul_si(x[i-1], var1, i-1, GMP_RNDN);
    mpfr_cos(x[i-1], x[i-1], GMP_RNDN);
    mpfr_fma(x[i-1], x[i-1], var2, var3, GMP_RNDN); /* x_i = [cos((i-1)*Pi/(p-1))]*(u-v)/2 + (u+v)/2 */
  }
  mpfr_set(x[0], u, GMP_RNDU);
  mpfr_set(x[p-1], v, GMP_RNDD);

  mpfr_clear(var1);
  mpfr_clear(var2);
  mpfr_clear(var3);

  return x;
}


mpfr_t *remezMatrix(node *w, mpfr_t *x, node **monomials_tree, int n, mp_prec_t *currentPrec) {
  mpfr_t var1, var2, var3, zero_mpfr;
  mpfr_t *M;
  int i,j,r, test;
  node *temp_tree, *temp_tree2;
  mp_prec_t prec= *currentPrec;

  M = (mpfr_t *)(safeMalloc((n+1)*(n+1)*sizeof(mpfr_t)));

  mpfr_init2(var1, prec);
  mpfr_init2(var2, prec);
  mpfr_init2(var3, prec);
  mpfr_init2(zero_mpfr, 53);
  mpfr_set_d(zero_mpfr, 0., GMP_RNDN);

  for (i=1 ; i <= n+1 ; i++) {
    mpfr_init2(M[coeff(i,n+1,n+1)], prec);
    if(i%2==0) mpfr_set_si(M[coeff(i,n+1,n+1)], 1, GMP_RNDN);
    else mpfr_set_si(M[coeff(i,n+1,n+1)], -1, GMP_RNDN);

    r = evaluateFaithfulWithCutOffFast(var1, w, NULL, x[i-1], zero_mpfr, prec);
    if(((r==1) || (r==4) || (r==5) || (r==6) || (r==7)) && (mpfr_number_p(var1))) test=1;
    else test=0;

    for (j=1 ; j <= n ; j++) {
      mpfr_init2(M[coeff(i,j,n+1)], prec);

      if(test==1) {
	r = evaluateFaithfulWithCutOffFast(var2, monomials_tree[j-1], NULL, x[i-1], zero_mpfr, prec);
	if(((r==1) || (r==4) || (r==5) || (r==6) || (r==7)) && (mpfr_number_p(var2))) {
	  mpfr_mul(var2, var1, var2, GMP_RNDN);
	  mpfr_set(M[coeff(i,j,n+1)],var2,GMP_RNDN);
	}
      }
      if((test==0) || (r==0) || (!mpfr_number_p(var2))) {
	printMessage(2,SOLLYA_MSG_REMEZ_COMPUTAT_OF_MATRIX_ENTRY_USES_SLOWER_ALGO,"Information: the construction of M[%d,%d] uses a slower algorithm\n",i,j);
	temp_tree = allocateNode();
	temp_tree->nodeType = MUL;
	temp_tree->child1 = copyTree(monomials_tree[j-1]);
	temp_tree->child2 = copyTree(w);
	temp_tree = addMemRef(temp_tree);

	temp_tree2 = simplifyTreeErrorfree(temp_tree);
	free_memory(temp_tree);
	temp_tree = temp_tree2; /* temp_tree = x^(monomials[j])*w(x) */

	r = evaluateFaithfulWithCutOffFast(var3, temp_tree, NULL, x[i-1], zero_mpfr, prec);

	if(r==0) mpfr_set_d(var3, 0., GMP_RNDN);
	mpfr_set(M[coeff(i,j,n+1)],var3,GMP_RNDN);

	free_memory(temp_tree);
      }
    }
  }


  mpfr_clear(zero_mpfr);
  mpfr_clear(var1);
  mpfr_clear(var2);
  mpfr_clear(var3);

  return M;
}


node *elementaryStepRemezAlgorithm(mpfr_t *h,
				   node *func, node *weight, mpfr_t *x,
				   node **monomials_tree, int n,
				   mp_prec_t *currentPrec) {
  mpfr_t *M;
  mpfr_t *b, *ai_vect;
  int i,j;
  mpfr_t zero_mpfr;
  node *poly;
  int r;

  mpfr_init2(zero_mpfr, 53);
  mpfr_set_d(zero_mpfr, 0., GMP_RNDN);

  b = (mpfr_t *)(safeMalloc((n+1)*sizeof(mpfr_t)));
  ai_vect = (mpfr_t *)(safeMalloc((n+1)*sizeof(mpfr_t)));

  for(i=0;i<=n;i++) {
    mpfr_init2(b[i], *currentPrec);
    r=evaluateFaithfulWithCutOffFast(b[i], func, NULL, x[i], zero_mpfr, *currentPrec);
    if (r == 0) mpfr_set_d(b[i], 0., GMP_RNDN);
  }

  for(i=0;i<=n;i++) mpfr_init2(ai_vect[i], *currentPrec);

  M = remezMatrix(weight, x, monomials_tree, n, currentPrec);
  system_solve(ai_vect, M, b, n+1, *currentPrec);

  poly = constructPolynomialFromArray(ai_vect, monomials_tree, n);
  if (h!=NULL)   mpfr_set(*h, ai_vect[n], GMP_RNDU);

  for(i=0;i<=n;i++) mpfr_clear(b[i]);
  safeFree(b);

  for(i=0;i<=n;i++) mpfr_clear(ai_vect[i]);
  safeFree(ai_vect);

  for(i=1;i<=n+1;i++) {
    for(j=1;j<=n+1;j++) mpfr_clear(M[coeff(i,j,n+1)]);
  }
  safeFree(M);

  mpfr_clear(zero_mpfr);
  return poly;
}

void radiusBasicMinimaxChebychevsPoints(mpfr_t *h, node *func, node *weight, mpfr_t a, mpfr_t b, int n, mp_prec_t *currentPrec) {
  mpfr_t *x;
  node **monomials_tree;
  int i;
  node *poly;

  monomials_tree = (node **)safeMalloc(n*sizeof(node *));
  monomials_tree[0] = addMemRef(makeConstantDouble(1.));
  for(i=1;i<n;i++) monomials_tree[i] = addMemRef(makePow(makeVariable(), makeConstantInt(i)));


  x = chebychevsPoints(a,b,n+1,currentPrec);
  perturbPoints(x, n+1, 2, 0, *currentPrec);
  poly = elementaryStepRemezAlgorithm(h, func, weight, x, monomials_tree, n, currentPrec);
  mpfr_abs(*h, *h, GMP_RNDN);

  free_memory(poly);

  for(i=0;i<n;i++) free_memory(monomials_tree[i]);
  safeFree(monomials_tree);

  for(i=0;i<=n;i++) mpfr_clear(x[i]);
  safeFree(x);

  return;
}

void firstStepContinuousMinimaxChebychevsPoints(mpfr_t *h, node *func, node *weight, mpfr_t a, mpfr_t b, int n, mp_prec_t *currentPrec) {
  mpfr_t *x;
  node **monomials_tree;
  int i;
  node *poly;
  node *error;
  mpfr_t tmp;

  mpfr_init2(tmp, 20);
  monomials_tree = (node **)(safeMalloc(n*sizeof(node *)));
  monomials_tree[0] = addMemRef(makeConstantDouble(1.));
  for(i=1;i<n;i++) monomials_tree[i] = addMemRef(makePow(makeVariable(), makeConstantInt(i)));

  x = chebychevsPoints(a,b,n+1,currentPrec);
  perturbPoints(x, n+1, 2, 0, *currentPrec);
  poly = addMemRef(elementaryStepRemezAlgorithm(NULL, func, weight, x, monomials_tree, n, currentPrec));

  error = addMemRef(makeSub(makeMul(copyTree(poly), copyTree(weight)), copyTree(func)));
  uncertifiedInfnorm(tmp, NULL, error, a, b, 3*n, 20);
  mpfr_set(*h, tmp, GMP_RNDU);

  mpfr_clear(tmp);
  free_memory(error);
  free_memory(poly);

  for(i=0;i<n;i++) free_memory(monomials_tree[i]);
  safeFree(monomials_tree);

  for(i=0;i<=n;i++) mpfr_clear(x[i]);
  safeFree(x);

  return;
}

rangetype guessDegree(node *func, node *weight, mpfr_t a, mpfr_t b, mpfr_t eps, int bound) {
  int n=1;
  int n_min, n_max;
  mp_prec_t prec = getToolPrecision();
  mpfr_t h;
  rangetype range;
  mpfr_t *tempMpfr;
  sollya_mpfi_t tmp1, tmp2;
  mp_prec_t prec_tmp;

  if (mpfr_number_p(a) && mpfr_number_p(b) && (mpfr_cmp(a,b) == 0)) {
    tempMpfr = (mpfr_t *)safeMalloc(sizeof(mpfr_t));
    mpfr_init2(*tempMpfr,12);
    mpfr_set_si(*tempMpfr, 0, GMP_RNDN);
    range.a = tempMpfr;
    
    tempMpfr = (mpfr_t *)safeMalloc(sizeof(mpfr_t));
    mpfr_init2(*tempMpfr,12);
    mpfr_set_si(*tempMpfr, 0, GMP_RNDN);
    range.b = tempMpfr;
    
    return range;
  }

  mpfr_init2(h, prec);

  if (messageHasEnoughVerbosityAndIsNotSuppressed(1, SOLLYA_MSG_GUESSDEGREE_POSSIBLE_SINGULAR_WEIGHT)) {
    prec_tmp = (mpfr_get_prec(a)>mpfr_get_prec(b))?(mpfr_get_prec(a)):(mpfr_get_prec(b));
    sollya_mpfi_init2(tmp1, prec_tmp);
    sollya_mpfi_init2(tmp2, 12);
    sollya_mpfi_interv_fr(tmp1, a, b);
    evaluateInterval(tmp2, weight, NULL, tmp1);
    if (sollya_mpfi_has_infinity(tmp2)) {
      printMessage(1, SOLLYA_MSG_GUESSDEGREE_POSSIBLE_SINGULAR_WEIGHT, "Warning: guessdegree: the weight function might not be continuous over the given interval.\nThis is not allowed but it is the user's responsibility to check it.\nNo other test will be performed, but be aware that the command is allowed to return anything in this case.\n");
    }
    sollya_mpfi_clear(tmp1);
    sollya_mpfi_clear(tmp2);
  }

  /* n reprensents the number of unknowns: n=1 corresponds to degree 0 */
  /* bound represents the maximal value allowed for n. If we do not find a
     suitable n<=bound, we return an interval [*, +inf]. We assume bound>=1 */

  /* We try n=1, 2, 4, 8, etc. until we find one for which the basic
     minimax problem achieve the required bound eps */
  pushTimeCounter();
  radiusBasicMinimaxChebychevsPoints(&h, func, weight, a, b, n, &prec);
  printMessage(4, SOLLYA_MSG_GUESSDEGREE_TRYING_A_CERTAIN_DEGREE, "Information: guessdegree: trying degree %d. Found radius: %v\n",n-1,h);


  /* If h<eps, we may be in a degenerated case (for instance, an even
     function on a symetrical interval, that leads to a huge difference
     between the radius of the basic minimax problem and of the continuous
     minimax problem. We try, n=2 for a confirmation. */
  if(mpfr_cmp(h,eps)<0) {
    n=2;
    radiusBasicMinimaxChebychevsPoints(&h, func, weight, a, b, n, &prec);
    printMessage(4, SOLLYA_MSG_GUESSDEGREE_TRYING_A_CERTAIN_DEGREE, "Information: guessdegree: trying degree %d. Found radius: %v\n",n-1,h);

    if (mpfr_cmp(h,eps)<0) n=1; /* OK. Sorry. The system seems to be normal */
  }

  /* Here, if n=1, it means that we are allowed to think that n=1 achieves the
     continuous problem (at least, based on what we can say from the discrete
     problem.)
     If n=2, it means that we know for sure that n=2 does not achieve the
     continuous problem.
  */

  while(mpfr_cmp(h,eps) >= 0) {
    n *= 2;
    if (n<bound)
      radiusBasicMinimaxChebychevsPoints(&h, func, weight, a, b, n, &prec);
    else {
      radiusBasicMinimaxChebychevsPoints(&h, func, weight, a, b, bound, &prec);
      break;
    }
    printMessage(4, SOLLYA_MSG_GUESSDEGREE_TRYING_A_CERTAIN_DEGREE, "Information: guessdegree: trying degree %d. Found radius: %v\n",n-1,h);
  }

  if (mpfr_cmp(h,eps) >=0) { /* Even n=bound does not achieve the discrete
                                problem, a fortiori it does not achieve the
                                continuous problem. Return [bound+1, +Inf]
                             */
    printMessage(1, SOLLYA_MSG_GUESSDEGREE_NONE_OF_LESSER_DEGS_SATISFIES_ERROR, "Warning: guessdegree: none of the degrees smaller than %d satisfies the required error.\n", bound-1);
    mpfr_clear(h);
    tempMpfr = (mpfr_t *)safeMalloc(sizeof(mpfr_t));
    mpfr_init2(*tempMpfr,128);
    mpfr_set_ui(*tempMpfr, bound, GMP_RNDN); /* n=bound+1 converts to degree bound */
    range.a = tempMpfr;

    tempMpfr = (mpfr_t *)safeMalloc(sizeof(mpfr_t));
    mpfr_init2(*tempMpfr,128);
    mpfr_set_inf(*tempMpfr, 1);
    range.b = tempMpfr;

    return range;
  }

  /* Now, the basic minimax problem achieves eps for min(n,bound) but not
     for n/2.
     We use a bisection to obtain a thinner bound.
     Note that if n=1 achieves the bound eps, we have nothing to do */
  if(n!=1) {
    n_min = n/2;
    n_max = (n<=bound)?n:bound;

    n = (n_min + n_max)/2;

    while(n != n_min) {
      radiusBasicMinimaxChebychevsPoints(&h, func, weight, a, b, n, &prec);
      printMessage(4, SOLLYA_MSG_GUESSDEGREE_TRYING_A_CERTAIN_DEG_WITHIN_BOUNDS, "Information: guessdegree: trying degree %d (current bounds: [%d, %d]). Found radius: %v\n",n-1,n_min-1,n_max-1,h);
      if(mpfr_cmp(h,eps) >= 0) n_min = n;
      else n_max = n;

      n = (n_min + n_max)/2;
    }
  }
  else n_max = 1;
  popTimeCounter("finding a lower bound for guessdegree");


  /* Now n_min = n = n_max - 1
     What we know for sure is: n_min is not sufficient to achieve
     the basic minimax problem. A fortiori, it is not sufficient for
     the continuous minimax problem.
     n_max is a possible candidate for the continuous minimax problem */
  n = n_max;

  pushTimeCounter();
  firstStepContinuousMinimaxChebychevsPoints(&h, func, weight, a, b, n, &prec);
  printMessage(4, SOLLYA_MSG_GUESSDEGREE_TRYING_A_CERTAIN_DEGREE, "Information: guessdegree: trying degree %d. Found infnorm: %v\n",n-1,h);

  while(mpfr_cmp(h,eps) > 0) {
    n++;
    if (n>bound) break;
    firstStepContinuousMinimaxChebychevsPoints(&h, func, weight, a, b, n, &prec);
    printMessage(4, SOLLYA_MSG_GUESSDEGREE_TRYING_A_CERTAIN_DEGREE, "Information: guessdegree: trying degree %d. Found infnorm: %v\n",n-1,h);
  }
  popTimeCounter("finding an upper bound for guessdegree");

  /* if (n>bound), it is possible that n_max suffices, but we did not manage to
     prove that n suffices for any n_max<=n<=bound. So we return [n_max, +Inf].
     Otherwise, we are sure that n is sufficient to achieve eps in the
     continuous problem. We return [n_max, n];
  */
  if (n>bound)
    printMessage(2, SOLLYA_MSG_GUESSDEG_NONE_OF_LESS_DEGS_SEEMS_TO_SATISFY_ERR, "Warning: guessdegree: we did not find a degree less than %d for which we can prove that the error is satisfied.\n", bound-1);

  mpfr_clear(h);
  tempMpfr = (mpfr_t *)safeMalloc(sizeof(mpfr_t));
  mpfr_init2(*tempMpfr,128);
  mpfr_set_ui(*tempMpfr, n_max-1, GMP_RNDN);
  range.a = tempMpfr;

  tempMpfr = (mpfr_t *)safeMalloc(sizeof(mpfr_t));
  mpfr_init2(*tempMpfr,128);
  if (n<=bound) mpfr_set_ui(*tempMpfr, n-1, GMP_RNDN);
  else mpfr_set_inf(*tempMpfr, 1);
  range.b = tempMpfr;

  return range;
}
