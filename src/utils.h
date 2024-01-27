#include <stdlib.h>
#include <stdio.h>

// AVX-512 used 64byte alignment
#define AVX512ALIGN 64

void sample_harmonic_signal(
  double const alpha, double const omega, double const phi,
  int const n, double* const v );

void copy_coo_to_dns( int const nz, int const ld, int const ncols,
  int const* const row, int const* const col, double const* const a,
  double* const val );

int get_ld( int const entries, int const type_cache_alignment );

void print_matrix( FILE * const f,
  int const ld, int const nrows, int const ncols, double const* const a );

void print_vector( FILE* const f,
  int const nrows, int const inc, double const* const v );
