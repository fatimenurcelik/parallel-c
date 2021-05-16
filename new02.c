
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  FILE *fp;
  FILE *fp2;
struct timeval start, stop;
  char *extension = "}.txt";
  char *extensiona = "a{";
  char *extensionb = "b{";

  int i, o, number2, **a,**b;
  number2 = atoi(argv[1]);
  a = (int**)malloc(number2*sizeof(int*));
  b = (int**)malloc(number2*sizeof(int*));
  char *number = argv[1];

  char fileSpec[strlen (number) + strlen (extension) + 1+strlen (extensiona) + 1];
  char fileSpec2[strlen (number) + strlen (extension) + 1+strlen (extensionb) + 1];

  int random[number2][number2];
  snprintf (fileSpec, sizeof (fileSpec), "%s%s%s",extensiona ,number, extension);
  snprintf (fileSpec2, sizeof (fileSpec), "%s%s%s",extensionb ,number, extension);
  
for (o = 0; o < number2; o++)
    {
        a[o] = (int*) malloc(number2*sizeof(int));
        b[o] = (int*) malloc(number2*sizeof(int));

    }
  printf ("%s\n", fileSpec);

  fp = fopen (fileSpec, "w");
  fp2 = fopen (fileSpec2, "w");
gettimeofday (&start, NULL);
  for (o = 0; o < number2; o++)
    {
      for (i = 0; i < number2; i++)
	{
	  a[o][i] = rand()%10;
	  b[o][i] = rand()%10;

	  fprintf (fp, "%d\n", a[o][i]);
	  fprintf (fp2, "%d\n", b[o][i]);

	}
	  fprintf (fp, "\n");
	  fprintf (fp2, "\n");

    }
  gettimeofday (&stop, NULL);
   printf ("Execution time: %3.5f seconds\n",
          ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec -
           start.tv_usec) / 1000000.0);
  fclose (fp);
  fclose (fp2);
  printf ("%d\n", number2);
  return 0;
}
