/*
   ESESC: Enhanced Super ESCalar simulator
   Copyright (C) 2010 University of California, Santa Cruz.

   Contributed by Ehsan K.Ardestani and Jose Renau

This file is part of ESESC.

ESESC is free software; you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation;
either version 2, or (at your option) any later version.

ESESC is distributed in the  hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
ESESC; see the file COPYING. If not, write to the Free Software Foundation, 59
Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>


#define __NR_esesccall 398  /* match it with the same syscall in qemu/linux-user/arm/syscall_nr.h */


void print_usage(char *name)
{
  printf("Usage: %s [-- reloop] [-- stdin stdin_file] -- benchname [bench_args] -- benchname [bench_args]\n", name);
  printf("Only one benchmark can be used with standard input.\n");
};



void spec_wrapper(void * thread_args);
void dummy_main();
void notify_esesc(const char * benchname, int *first, int *done);


struct thread_data
{
  int argc;
  char **argv;
  int done;
};


char *deliminator="--";
int  benchCnt;
int  reloop = 0;

int main(int argc, char *argv[]) {

  char *env[] = { 0 };
  char stdinf[255];
  pthread_t threads[32];
  int rt[32];

  if (argc < 2)
  {
    print_usage(argv[0]);
    return -1;
  }

  int i=0, j, k;
	benchCnt = 0;
	//struct thread_data *last_args = (struct thread_data *) malloc(sizeof(struct thread_data));
	struct thread_data **thread_args = (struct thread_data **) malloc(32*sizeof(struct thread_data*));
  for(j=0;j<32;j++)
    thread_args[j] = (struct thread_data *) malloc(sizeof(struct thread_data));

  while(argv[i])
  {
    while((argv[i]) && (strcmp(argv[i] , deliminator)!=0) && (strcmp(argv[i],"<")!=0)){i++;}; // advance to next "--"
    if (!argv[i])
    {
      print_usage(argv[0]);
      return 0;
    }
    j = ++i; // start of the new argv
    while((argv[i]) && (strcmp(argv[i] , deliminator)!=0) && (strcmp(argv[i],"<")!=0)){i++;}; // advance to next "--" or 0x0
    k = i-1; // end of the new argv

    char **argv1 = (char **) malloc((k-j+1)*sizeof(char *));
    int g = 0;
    for (g=0;g<k-j+1;g++)
    {
      argv1[g] = (char *)malloc(1024*sizeof(char)); 
      strcpy(argv1[g], argv[j+g]);
      printf("%d %d %s\n", i, j, argv1[g]);
    }
    if (strcmp(argv1[0], "stdin")!=0 && strcmp(argv1[0], "reloop") !=0)
    {
      thread_args[benchCnt]->argc = k-j+1;
      thread_args[benchCnt]->argv = argv1;
      thread_args[benchCnt]->done = 0;

      if (argv[i]){ // the last workload to be called as a function
        printf("spawn thread ... %s\n", argv1[0]);
        rt[benchCnt] = pthread_create(&threads[benchCnt], NULL, spec_wrapper,(void *) thread_args[benchCnt]);
      }else{
        printf("function ... %s\n", argv1[0]);
        spec_wrapper(thread_args[benchCnt]);
      }

      if (benchCnt++ > 32)
      {
        printf("Max threads 32!\n");
        return;
      }
    }else if (strcmp(argv1[0], "stdin")==0)
    {
      strcpy(stdinf,argv1[1]);
      fclose(stdin);
      freopen(stdinf, "r", stdin);
    }else {
			reloop = 1;
		}
  }

  int g;

  do
  {
    for (g=0;g<benchCnt;g++)
    {
      if (thread_args[g]->done != 0) 
      {
        if (g == 0)
          {
          printf("The stdin Thread:%d (%s) Completed!\n", g, thread_args[g]->argv[0]);
          //fclose(stdin);
          freopen(stdinf, "r", stdin);
          }
          else
        {
          printf("re-lunching thread:%d %s\n", g, thread_args[g]->argv[0]);
          thread_args[g]->done =0;
          rt[g] = pthread_create(&threads[g], NULL, spec_wrapper,(void *) thread_args[g]);
        }
      }
    }
  }while(0);

}



void spec_wrapper(void * thread_args){
  struct thread_data *my_data;
  my_data  = (struct thread_data *) thread_args;
	static int done = 0;
	int first       = 1;

  int argc = my_data->argc;
  char **argv = my_data->argv;
  char *benchname = my_data->argv[0];
  if (strcmp(benchname, "dummy") == 0)
    dummy_main();
  else if (strcmp(benchname, "crafty") == 0){
    printf("LAUNCHER Warning: crafty can be launched once.\n"); 
    do{
      crafty_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    } while(reloop);
  }else if (strcmp(benchname, "mcf") == 0)
    do{
      mcf_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  //  else if (strcmp(benchname, "gcc") == 0)
  //    do{
  //      gcc_main(argc, argv);
  //	      notify_esesc(benchname, &first, &done);
  //      }while(reloop);
  else if (strcmp(benchname, "vpr") == 0)
    do{
      vpr_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  //   else if (strcmp(benchname, "perlbmk") == 0)
  //    do{
  //      perlbmk_main(argc, argv);
  //			notify_esesc(benchname, &first, &done);
  //      }
  else if (strcmp(benchname, "gap") == 0)
    do{
      gap_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "vortex") == 0)
    do{
      vortex_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "twolf") == 0)
    do{
      twolf_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "swim") == 0)
    do{
      swim_main();
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "wupwise") == 0)
    do{
      wupwise_main();
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "mgrid") == 0)
    do{
      mgrid_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "applu") == 0)
    do{
      applu_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "mesa") == 0)
    do{
      mesa_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "art") == 0){
    printf("LAUNCHER Warning: only one instance of art can be called\n"); 
    do{
      art_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  }else if (strcmp(benchname, "equake") == 0)
    do{
      equake_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  //  else if (strcmp(benchname, "gzip") == 0)
  //    do{
  //      gzip_main(argc, argv);
  //			notify_esesc(benchname, &first, &done);
  //}
  else if (strcmp(benchname, "parser") == 0)
    do{
      parser_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  /*	else if (strcmp(benchname, "eon") == 0)
      eon_main(argc, argv);
      else if (strcmp(benchname, "bzip2") == 0)
      bzip2_main(argc, argv);
      else if (strcmp(benchname, "sixtrack") == 0)
      sixtrack_main(argc, argv);
      else if (strcmp(benchname, "apsi") == 0)
      apsi_main(argc, argv);
      else if (strcmp(benchname, "fma3d") == 0)
      fma3d_main(argc, argv);
      else if (strcmp(benchname, "lucas") == 0)
      lucas_main(argc, argv);
      else if (strcmp(benchname, "ammp") == 0)
      ammp_main(argc, argv);
      else if (strcmp(benchname, "facerec") == 0)
      facerec_main(argc, argv);
      else if (strcmp(benchname, "galgel") == 0)
      galgel_main(argc, argv);*/
  else if (strcmp(benchname, "perlbench") == 0)
    do{
      perlbench_06_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "bzip2_06") == 0)
    do{
      bzip2_06_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "gcc_06") == 0)
    do{
      gcc_06_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "bwaves") == 0) 
    do{
      bwaves_06_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  //  else if (strcmp(benchname, "mcf_06") == 0) // Needs too much memory
  //    do
  //      mcf_06_main(argc, argv);
	//while(reloop);
  else if (strcmp(benchname, "milc") == 0)
    do{
      milc_06_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "leslie3d") == 0)
    do{
      leslie3d_06_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "namd") == 0)
    do{
      namd_06_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "soplex") == 0)
    do{
      soplex_06_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "povray") == 0)
    do{
      povray_06_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  //  else if (strcmp(benchname, "hmmer") == 0)
  //    do
  //      hmmer_06_main(argc, argv);
	//while(reloop);
  //  else if (strcmp(benchname, "sjeng") == 0) // armel runs, armelrate with launcher fails
  //    do
  //      sjeng_06_main(argc, argv);
	//while(reloop);
  else if (strcmp(benchname, "libquantum") == 0)
    do{
      libquantum_06_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  //  else if (strcmp(benchname, "h264ref") == 0) // segfault, check armel?
  //    do
  //      h264ref_06_main(argc, argv);
//  else if (strcmp(benchname, "lbm") == 0)
//    do{
//      lbm_06_main(argc, argv);
//      notify_esesc(benchname, &first, &done);
//    }while(reloop);
  else if (strcmp(benchname, "astar") == 0)
    do{
      astar_06_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "sphinx3") == 0)
    do{
      sphinx3_06_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "dealII") == 0)
    do{
      dealII_06_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
 // 	else if (strcmp(benchname, "backprop") == 0)
 // 		do{
 //       backprop_main(argc, argv);
 // 			notify_esesc(benchname, &first, &done);
 // 		}
 // 	else if (strcmp(benchname, "bfs") == 0) 
 //     do{
 //       bfs_main(argc, argv);
 //       notify_esesc(benchname, &first, &done);
 //     }while(reloop);

 // 	else if (strcmp(benchname, "transpose") == 0) {
 // 	  do {  
 //       transpose_main(argc, argv);
 //       notify_esesc(benchname, &first, &done);
  //    } while(reloop);
//	      while (1);
//		}
   
  else if (strcmp(benchname, "blackscholes") == 0)
    do{
      blackscholes_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "fluidanimate") == 0)
    do{
      fluidanimate_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  //else if (strcmp(benchname, "freqmine") == 0)
  //	do{
  //    freqmine_main(argc, argv);
  //		notify_esesc(benchname, &first, &done);
  //	}while(reloop);
  else if (strcmp(benchname, "swaptions") == 0)
    do{
      swaptions_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "x264") == 0)
    do{
      x264_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "bodytrack") == 0)
    do{
      bodytrack_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "facesim") == 0)
    do{
      facesim_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "ferret") == 0)
    do{
      ferret_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "canneal") == 0)
    do{
      canneal_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
//  else if (strcmp(benchname, "dedup") == 0)
//    do{
//      dedup_main(argc, argv);
//      notify_esesc(benchname, &first, &done);
//    }while(reloop);
  else if (strcmp(benchname, "ocean") == 0)
    do{
      ocean_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "fft") == 0)
    do{
      fft_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "lu") == 0)
    do{
      lu_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "radix") == 0)
    do{
      radix_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else if (strcmp(benchname, "fmm") == 0)
    do{
      fmm_main(argc, argv);
      notify_esesc(benchname, &first, &done);
    }while(reloop);
  else 
    printf("Cannot find the specified benchmark. Check the spelling\n");

  printf("%s is DONE!\n", benchname);
  my_data->done = 1;
  exit(NULL);
}

void dummy_main(){
  printf("Hi from Dummy main!\n");
  printf("Dummy main will never exit!\n");
  while (1);
}

void notify_esesc(const char * benchname, int *first, int *done){

	if (*first){
		(*done)++;
		(*first) = 0;
		printf("It is the first for %s %d\n", benchname, *done);
	}

	if ((*done) == (1+benchCnt)){
		printf("All jobs (%d) finished.\n", (*done));
    exit(0);
	}else{
    if (reloop){
      printf("\n\nRelaunching %s and notifying eSESC\n\n", benchname);
      syscall(__NR_esesccall);
    }else{
      printf("Not all jobs are done, but %s finished!\n", benchname);
      printf("add -- reloop as the first argument to the launcher to enable relaunching until all jobs are done.\n");
    }
  }
}
