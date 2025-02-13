#include <stdlib.h>
#include <stdio.h>

#include <cblas.h>

#include "utils.h"

static void scale_vector( vector* const v, double const alpha )
{
  // call the DAXPY function of BLAS with appropriate arguments
}

static void test_daxpy()
{
  double const alpha = 2.0;
  
  int const nrows = 2;
  int const inc = 1;
  int const size = nrows*inc;
  double* const data = (double*) malloc( size * sizeof(double) );
  if ( data == NULL ) {
    fprintf( stderr, "Memory allocation failed.\n" );
    exit( EXIT_FAILURE );
  }

  data[0] = 1.0;
  data[1] = 2.0;

  vector v;
  v.data = data;
  v.inc = inc;
  v.nrows = nrows;
  v.size = size;

  printf( "*** Original vector X ***\n" );
  print_vector_struct( stdout, &v ); 
  scale_vector( &v, alpha );
  printf( "*** %f*X ***\n", alpha );
  print_vector_struct( stdout, &v ); 

  free(data);
}

int main( int argc, char** argv )
{
  if ( argc != 1 ) {
    fprintf( stderr, "Usage: %s\n", argv[0] );
    return EXIT_FAILURE;
  }

  test_daxpy();

  return EXIT_SUCCESS;
}
