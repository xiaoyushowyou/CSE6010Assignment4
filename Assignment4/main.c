//
//  main.c
//  Assignment4
//
//  Created by Xiaoyu Yang on 10/17/17.
//  Copyright © 2017 Learning. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <omp.h>
#define NUM_THREADS 4



int main(int argc, const char * argv[]) {
    srand(time(NULL));
    int myNumber = 10;
    double myPoss = 0.9;
    //initialize the graph
    char ** myGraph;
    if((myGraph = (char**)malloc(myNumber*sizeof(char*)))==NULL) {
        printf("Error-not enough memory to initialize myGraph");
        return (1);
    }

    //initialize the edge components for vertex
    for (int i = 0; i < myNumber; i++) {
        if((*(myGraph+i) = (char*)malloc(myNumber*sizeof(char))) == NULL) {
            printf("Error-not enough memory to initialize myGraph");
            return (1);
        }
    }
    
    //initialize a list to record how many elements inside
    int * counter = NULL;
    for (int k = 0; k < myNumber; k++) {
        if((counter = (int*)malloc(myNumber*sizeof(int))) == NULL) {
            printf("Error-not enough memory to initialize counter");
        }
    }
//    omp_set_num_threads(NUM_THREADS);
//    #pragma omp parallel
//    {
    //add elements into the graph
    for (int i = 0; i < myNumber-1; i++) {
    //#pragma omp critical{
        int myCount = 0;
        for (int j = i+1; j < myNumber; j++) {
            if (rand()%100<=myPoss*100) {
                *(*(myGraph+i)+myCount) = j;
                myCount++;
            }
        }
        *(counter+i) = myCount;
    }
    // }
    //}
    
    //print results
    for (int i = 0; i < myNumber; i++) {
        printf("Node %d Edge",i);
        if (*(counter+i) != 0) {
            for (int j = 0; j < *(counter+i); j++) {
                printf(" %d",*(*(myGraph+i)+j));
            }
        }
        printf("\n");
    }
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//
//int main(int argc, const char * argv[]) {
//    srand(time(NULL));
//    int myNumber = 10;
//    double myPoss = 0.5    ;
//    //initialize the graph
//    char *** myGraph;
//    if((myGraph = (char***)malloc(myNumber*sizeof(char**)))==NULL) {
//        printf("Error-not enough memory to initialize myGraph");
//        return (1);
//    }
//
//    //initialize the edge components for vertex
//    for (int i = 0; i < myNumber; i++) {
//        if((*(myGraph+i) = (char**)malloc(myNumber*sizeof(char*))) == NULL) {
//            printf("Error-not enough memory to initialize myGraph");
//            return (1);
//        }
//
//        //initialize the target nodes component
//        for (int j = 0; j < myNumber; j++) {
//            if((*(*(myGraph+i)+j) = (char*)malloc(sizeof(char))) == NULL) {
//                printf("Error-not enough memory to initialize myGraph");
//                return (1);
//            }
//        }
//    }
//
//    //add elements into the graph
//
//    for (int i = 0; i < myNumber; i++) {
//        printf("myNode %d", i);
//        for (int j = i+1; j < myNumber; j++) {
//            if (rand()%100<=myPoss*100) {
//                printf("myEdge %d\n", j);
//                *(*(myGraph+i)+j) = *(myGraph+j);
//            }
//        }
//    }
//
//    printf("myNode, %s",*(myGraph+2));
//    printf("myEdge, %s",*(*myGraph+2));
//
//}

