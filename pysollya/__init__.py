# pysollya — Self-contained Python wrapper for the Sollya library
"""
Usage::

    import pysollya
    from pysollya import *

    x = pysollya.x
    f = sin(x) / x
    p = remez(f, 5, Interval(-1, 1))
    print(p)
"""
from pysollya._pysollya import *  # noqa: F401,F403
from pysollya._pysollya import SollyaObject, Interval, S, parse  # noqa: F401
