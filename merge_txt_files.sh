#! /usr/bin/bash

#merge EB alignment txt files
touch EBAlignmentCoefficients_merged.txt 
for i in {0..35}
do
    cat EBAlignmentCoefficients_${i}.txt >> EBAlignmentCoefficients_merged.txt 
done   
echo "EB alignment coefficient txt files merged!"


#merge EE alignment txt files
touch EEAlignmentCoefficients_merged.txt
for i in {0..3}
do
    cat EEAlignmentCoefficients_${i}.txt>> EEAlignmentCoefficients_merged.txt
done
echo "EE alignment coefficient txt files merged!"
