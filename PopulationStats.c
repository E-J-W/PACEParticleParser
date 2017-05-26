#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{

  FILE *inp;
  char str[16][132];
  int initN=-1;
  int initZ=-1;
  int numParticles=0;
  double initExi,finExi,Jinit,Jfin;
  double iEm=0.;
  double iEs=0.;
  double fEm=0.;
  double fEs=0.;
  double iJm=0.;
  double iJs=0.;
  double fJm=0.;
  double fJs=0.;

  if(argc!=2)
    {
      printf("PACE_PopulationStats particles_file\n");
      printf("\nCalculates stats for spin and excitation energy of residual nuclei following particle evaporation from PACE4 .particles files.\n");
      exit(-1);
    }

  //read in command line arguments
  if((inp=fopen(argv[1],"r"))==NULL)
      {
         printf("\nFile %s can not be opened\n",argv[1]);
         exit(-1);
      }

  //read the .particles file
  if(fgets(str[0],132,inp)!=NULL)
    {
		  if(fgets(str[0],132,inp)!=NULL)
		    while(fscanf(inp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",str[0],str[1],str[2],str[3],str[4],str[5],str[6],str[7],str[8],str[9],str[10],str[11],str[12],str[13],str[14],str[15])!=EOF)
					{
						if(initN==-1)
							if(initZ==-1)
								{
									initZ=atoi(str[6]);
									initN=atoi(str[7]);
									printf("Initial nucleus: Z=%i, N=%i\n",initZ,initN);
								}
						
						if(atoi(str[6])==initZ)
							if(atoi(str[7])==initN)
								{
									Jinit = atof(str[8]);
									Jfin = atof(str[9]);
									initExi = atof(str[12]);
									finExi = atof(str[13]);
						
									//make sums for means
									iJm+=Jinit;
									fJm+=Jfin;
									iEm+=initExi;
									fEm+=finExi;
									numParticles++;
								}
						
		      }
		  else
		    {
		      printf("Wrong structure of file %s.\n",argv[1]);
		      printf("Aborting...\n");
		      exit(1);
		    }
    }
  else
    {
      printf("Wrong structure of file %s.\n",argv[1]);
      printf("Aborting...\n");
      exit(1);
    }
  fclose(inp);
  
  //compute means
  iJm/=(numParticles*1.);
	fJm/=(numParticles*1.);
	iEm/=(numParticles*1.);
	fEm/=(numParticles*1.);
  
  
  //reopen and rescan file to get stdevs
	if((inp=fopen(argv[1],"r"))==NULL)
    {
       printf("\nFile %s can not be opened\n",argv[1]);
       exit(-1);
    }
  //read the .particles file
  if(fgets(str[0],132,inp)!=NULL)
    {
		  if(fgets(str[0],132,inp)!=NULL)
		    while(fscanf(inp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",str[0],str[1],str[2],str[3],str[4],str[5],str[6],str[7],str[8],str[9],str[10],str[11],str[12],str[13],str[14],str[15])!=EOF)
					{
					
						if(atoi(str[6])==initZ)
							if(atoi(str[7])==initN)
								{
									Jinit = atof(str[8]);
									Jfin = atof(str[9]);
									initExi = atof(str[12]);
									finExi = atof(str[13]);
						
									//make sums for means
									iJs+=(Jinit - iJm)*(Jinit - iJm);
									fJs+=(Jfin - fJm)*(Jfin - fJm);
									iEs+=(initExi - iEm)*(initExi - iEm);
									fEs+=(finExi - fEm)*(finExi - fEm);
								}
						
		      }
		  else
		    {
		      printf("Wrong structure of file %s.\n",argv[1]);
		      printf("Aborting...\n");
		      exit(1);
		    }
    }
  else
    {
      printf("Wrong structure of file %s.\n",argv[1]);
      printf("Aborting...\n");
      exit(1);
    }
    
  iJs/=(numParticles-1.);
	fJs/=(numParticles-1.);
	iEs/=(numParticles-1.);
	fEs/=(numParticles-1.);
	iJs=sqrt(iJs);
	fJs=sqrt(fJs);
	iEs=sqrt(iEs);
	fEs=sqrt(fEs);
	
	printf("\n\nFollowing particle evaporation...\n");
	printf("Inital spin: mean = %f, stdev = %f\n",iJm,iJs);
	printf("Final spin: mean = %f, stdev = %f\n",fJm,fJs);
	printf("Inital excitation energy (MeV): mean = %f, stdev = %f\n",iEm,iEs);
	printf("Final excitation energy (MeV): mean = %f, stdev = %f\n",fEm,fEs);

  return(1); //great success
}
