/** pex3main.c
 * ===========================================================
 * Name: C3C Cleo Cowie, 26 Oct 2020
 * Section: T1/2
 * Project: PEX3
 * Purpose: File I/O, structs, string manipulation
 * Documentation: C3C Jay Stearns explained how to complete the countMatches 
 * function by using placeholder strings to compare to the genome sequence. 
 * ===========================================================
 */

#include "pex3functs.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {

    int numSequences;
    DNA knownSequences[500];
    numSequences = readFile("pex3Data1.txt",knownSequences);

//testing output of fucntions

    printf("%d\n",numSequences);
    printSequences(knownSequences,numSequences);
    printf("hamming = %d\n", hammingDistance("AAA", "CC")); // result= -1
    printf("hamming = %d\n", hammingDistance("ACCT", "ACCG")); //result= 1
    printf("hamming = %d\n", hammingDistance("ACGGT", "CCGTT")); //result= 2
    printf("simularity = %0.3f\n", similarityScore("CCC", "CCC")); // result= 1.0
    printf("simularity = %0.3f\n", similarityScore("ACCT", "ACCG")); // result= 0.75
    printf("simularity = %0.3f\n", similarityScore("ACGGT", "CCGTT")); // result= 0.6
    printf("simularity = %0.3f\n", similarityScore("CCGCCGCCGA", "CCTCCTCCTA")); // result= 0.7
    printf("# matches = %d\n", countMatches("CCGCCGCCGA", "TTT", 0.6)); // result= 0
    printf("# matches = %d\n", countMatches("CCGCCGCCGA", "CCG", 0.2)); // result= 8
    printf("# matches = %d\n", countMatches(knownSequences[1].dna, "CGCTT", 0.5)); // result= 36
    printf("# matches = %d\n", countMatches(knownSequences[0].dna, "CGC", 0.3)); // result= 215
    printf("best match = %0.3f\n", findBestMatch("CCGCCGCCGA", "TTT")); // result= 0.0
    printf("best match = %0.3f\n", findBestMatch("CTGCCACCAA", "CCGC")); // result= 0.75
    printf("best match = %0.3f\n", findBestMatch(knownSequences[2].dna, "CGCTT")); // result= 0.8
    printf("best match = %0.3f\n", findBestMatch(knownSequences[0].dna, "CGC")); // result= 1.0
    printf("likely genome match = %s\n", knownSequences[findBestGenome(knownSequences, numSequences, "CTTTAGGCCGGTT")].species); //result=Cat
    printf("likely genome match = %s\n", knownSequences[findBestGenome(knownSequences, numSequences, "CTTTAGGCCGGG")].species); //result= Human
    printf("likely genome match = %s\n", knownSequences[findBestGenome(knownSequences, numSequences, "CTTAATTCTTTT")].species); //result= Mouse  
  
    system("pause");
    
    return 0;
}

