/** pex3functs.c
 * ===========================================================
 * Name: C3C Cleo Cowie, 26 Oct 2020
 * Section: T1/2
 * Project: PEX3
 * Purpose: File I/O, structs, string manipulation
 * ===========================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include "pex3functs.h"

/** ----------------------------------------------------------
 * readFile() - reads in DNA sequences from a text file 
 * and stores them in an array of structs
 * @param fileName is the file being read
 * @param sequences array of DNA structures
 * @return the number of DNA sequences read from the file
 * ----------------------------------------------------------
 */
int readFile(char fileName[], DNA sequences[]) {

    int numRead = 0; 
// Open an input file for reading
    FILE *data = fopen(fileName, "r");

    if (data == NULL) {
        printf("Error opening data file:\n");
    }

    while (!feof(data)) {
        fscanf(data, "%s %s",sequences[numRead].species,sequences[numRead].dna);  //Reading input from file
        numRead++;
    }

    fclose(data);

    return numRead-1;
}

/** ----------------------------------------------------------
 * printSequences() - prints out all DNA sequences stores in a DNA array. 
 * @param sequences is the array of sequences
 * @param numSeq is the number of sequences in the array
 * @return no return value
 * ----------------------------------------------------------
 */
void printSequences(DNA sequences[],int numSeq) { 


    for (int i = 0 ; i < numSeq; i++) {
        printf("DNA Type-> %s\nSequence-> %s\n",sequences[i].species,sequences[i].dna); //prints DNA type and Sequence of that DNA type
        printf("\n");
    }

    return;
}

/** ----------------------------------------------------------
 * hammingDistance() - computes similarity between two strings of the same length
 * @param str1 is string 1
 * @param str2 is string 2
 * @return the hamming distance
 * ----------------------------------------------------------
 */
int hammingDistance(char str1[],char str2[]) {

    int length1;
    int length2;
    int i = 0;
    int hammingDistance = 0;  
    length1 = strlen(str1);  
    length2 = strlen(str2);

    if (length1 != length2) {    //if the two sequences we are comparing do not have the same length,it becomes an invalid comparison
        return -1;              //return -1 if lengths are not the same
    }

    else {

        while (i < length1)           //while number of characters is less than length of string
        {
            if (str1[i] != str2[i]) { //comparing individual characters within string
                hammingDistance++;  //if characters are not the same, hammingDistance increases
            }
            i++;
        }
        
    }

    return hammingDistance;
}

/** ----------------------------------------------------------
 * similarityScore() - finds similarity score
 * @param seq1 is sequence 1
 * @param seq2 is sequence 2
 * @return the result of similarity score
 * ----------------------------------------------------------
 */
float similarityScore(char seq1[],char seq2[]) {
    
    float similarityScore;
    int length1;
    int length2;
    int i = 0;
    int distance = 0;
    length1 = strlen(seq1);
    length2 = strlen(seq2);

    distance = hammingDistance(seq1,seq2); //finding hammingDistance

    similarityScore = ((float)(length1-distance))/length1; //formula to find similarityScore

    return similarityScore;
}

/** ----------------------------------------------------------
 * countMatches() - counts the number of matches a given sequence has in a given genome
 * @param genome is the entire genome sequece
 * @param seq is the sequence being examined in the genome
 * @return number of matches found
 * ----------------------------------------------------------
 */
int countMatches(char genome[],char seq[],float minScore) {
  
	int countMatches = 0;
    int length1 = strlen(genome);
    int length2 = strlen(seq);
    int position = 0;
    int offset = 0;
    
	char * placeholder = malloc(sizeof(char) * strlen(seq)); //dynamically allocating memory to hold how many times the sequence check through genome

    for (position = 0; position < length1-length2 + 1 ; position++) //changing position from where sequence and genome are compared
    {
       //iterates over length of genome, builds placeholder of genome
       for (offset = 0; offset < length2; offset++){ //offset variable is the position plus how many characters are in the given sequence
        placeholder[offset] = genome[position+offset]; 
       }
       
       placeholder[length2] = '\0'; 

       if (similarityScore(placeholder,seq) > minScore) { //counting matches based on if the similarity score is above the given minScore
           countMatches++;
       }
    }

    return countMatches;
}

/** ----------------------------------------------------------
 * findBestMatch() - selects the best match by comparing similarity scores at every position
 * @param genome is entire genome sequence
 * @param seq is the sequence being examined in the genome
 * @return highest similarity score
 * ----------------------------------------------------------
 */
float findBestMatch(char genome[],char seq[]) {

    int length1 = strlen(genome);
    int length2 = strlen(seq);
    int position = 0;
    int offset = 0;
    float maxSoFar[500];  
    float maxVal = 0;   
   
	char * placeholder = malloc(sizeof(char) * strlen(seq));

    for (position = 0; position < length1-length2 + 1 ; position++)
    {
        //iterates over length of genome, builds placeholder of genome
        for (offset = 0; offset < length2; offset++){ //offset variable is the position plus how many characters are in the given sequence
        placeholder[offset] = genome[position+offset];
        
       }
       placeholder[length2] = '\0';

        maxSoFar[position] = similarityScore(placeholder,seq); //determines the similarity score for each position 
       
    }

   for (position = 0; position< length1-length2 + 1 ; position++) {
       if(maxSoFar[position] > maxVal) {  //compares the similarity score to the current max value
           maxVal = maxSoFar[position];   //if similarity score value of a position is higher than the current max value, new max value is established
       }
   }

    return maxVal;
}

/** ----------------------------------------------------------
 * findBestGenome() - finds best match in the array of genome sequences when given a sequence to match
 * @param sequences array of DNA structures
 * @param numSeq number of sequences in the array
 * @param unknownSeq the unknown sequence getting compared
 * @return the index of the genome array indicating where the best match was found
 * ----------------------------------------------------------
 */
int findBestGenome(DNA sequences[],int numSeq,char unknownSeq[]){

    float score[500];
    float max = 0.00;
    int maxVal = 0;

    for (int i = 0 ; i < numSeq; i++) {
       score[i] = findBestMatch(sequences[i].dna,unknownSeq);  //stores scores of highest similarity
    }

    for (int j = 0; j <numSeq; j++) //finds highest match in the array of genome sequences
    {
        if (score[j] > max) {
            max = score[j];
            maxVal = j;
        }
    }
    
    return maxVal;
}
 

