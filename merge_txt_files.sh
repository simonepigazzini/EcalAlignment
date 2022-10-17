#! /usr/bin/bash

#merge EB alignment txt files 
for i in {0..35}
do
    cat EBAlignmentCoefficients_${i}.txt >> EBAlignmentCoefficients_merged.txt 
    cat EBAlignmentCoefficients_${i}.txt.bis >> EBAlignmentCoefficients_with_err_merged.txt 
done   
echo "EB alignment coefficient txt files merged!"


#merge EE alignment txt files
for i in {0..3}
do
    cat EEAlignmentCoefficients_${i}.txt >> EEAlignmentCoefficients_merged.txt
    cat EEAlignmentCoefficients_${i}.txt.bis >> EEAlignmentCoefficients_with_err_merged.txt
done
echo "EE alignment coefficient txt files merged!"
