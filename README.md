# pysollya

[![CI](https://github.com/nibrunie/pysollya/actions/workflows/ci.yml/badge.svg)](https://github.com/nibrunie/pysollya/actions/workflows/ci.yml)

**pysollya** is a self-contained Python wrapper for the [Sollya](https://www.sollya.org/) numerical library.
It compiles the Sollya C/C++ sources directly into a Python extension module, so no pre-installed `libsollya` is required.

Sollya is an interactive tool mainly for the design of efficient floating-point implementations of mathematical functions. It provides polynomial approximation (Remez, fpminimax), Taylor models, interval arithmetic, and much more.

## Features

- **Polynomial approximation** — Remez algorithm, fpminimax, Taylor expansions
- **Arbitrary precision** — backed by MPFR/GMP interval arithmetic
- **Symbolic expressions** — manipulate, differentiate, simplify mathematical expressions
- **Self-contained build** — Sollya 8.0 sources are included and compiled automatically

## Requirements

The following C/C++ libraries must be available on your system:

| Library   | Ubuntu/Debian package | Purpose                         |
|-----------|-----------------------|---------------------------------|
| GMP       | `libgmp-dev`          | Arbitrary precision integers    |
| MPFR      | `libmpfr-dev`         | Arbitrary precision floats      |
| MPFI      | `libmpfi-dev`         | Arbitrary precision intervals   |
| fplll     | `libfplll-dev`        | Lattice reduction (for fpminimax) |
| libxml2   | `libxml2-dev`         | XML support                     |

On Ubuntu/Debian:

```bash
sudo apt-get install libgmp-dev libmpfr-dev libmpfi-dev libfplll-dev libxml2-dev
```

On macOS (Homebrew):

```bash
brew install gmp mpfr libxml2
```

> **Note:** `mpfi` and `fplll` may need to be built from source on macOS.
> You can point the build to custom install prefixes via environment variables (see [Configuration](#configuration)).

You also need Python ≥ 3.8, a C/C++ compiler, and [Cython](https://cython.org/) ≥ 0.29.

## Installation

```bash
pip install .
```

The build process will:
1. Run `./configure` inside the bundled `sollya-8.0/` source tree to generate `config.h`
2. Cythonize the `.pyx` bindings
3. Compile all Sollya C/C++ sources and link them into the extension module

## Quick Start

```python
import pysollya
from pysollya import *

# Symbolic variable
f = sin(x) / x

# Remez polynomial approximation of degree 5 on [-1, 1]
p = remez(f, 5, Interval(-1, 1))
print(p)

# Approximation error
err = infnorm(f - p, Interval(-1, 1))
print(err)

# Taylor expansion
t = taylor(sin(x), 5, S("0"))
print(t)

# Differentiation
d = diff(p)
print(d)

# Precision control
set_prec(S("200"))
print(get_prec())
```

## Configuration

Dependency install prefixes can be specified via environment variables:

| Variable         | Description                              |
|------------------|------------------------------------------|
| `SOLLYA_DEP_DIR` | Common prefix for all dependencies       |
| `GMP_DIR`        | GMP install prefix (overrides common)    |
| `MPFR_DIR`       | MPFR install prefix (overrides common)   |
| `MPFI_DIR`       | MPFI install prefix (overrides common)   |
| `FPLLL_DIR`      | fplll install prefix (overrides common)  |
| `XML2_DIR`       | libxml2 install prefix (overrides common)|

Example:

```bash
export SOLLYA_DEP_DIR=/opt/local
pip install .
```

## Running Tests

```bash
pip install ".[dev]"
pytest tests/ -v
```

## License

The **pysollya** Python bindings are released under the [MIT License](LICENSE).

This project bundles source code from [Sollya 8.0](https://www.sollya.org/), which is released under the **CeCILL-C Free Software License** (a French LGPL-compatible license). See [`sollya-8.0/COPYING`](sollya-8.0/COPYING) for the full Sollya license text.

Credit were credit is due, the list of sollya authors is available in [`sollya-8.0/AUTHORS`](sollya-8.0/AUTHORS).

The Sollya library links against the following libraries, each under their own licenses:

- **GMP** — [LGPL v3+](https://gmplib.org/)
- **MPFR** — [LGPL v3+](https://www.mpfr.org/)
- **MPFI** — [LGPL v2.1+](https://gitlab.inria.fr/mpfi/mpfi)
- **fplll** — [LGPL v2.1+](https://github.com/fplll/fplll)
- **libxml2** — [MIT License](https://gitlab.gnome.org/GNOME/libxml2)
