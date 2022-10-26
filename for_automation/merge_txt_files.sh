#! /usr/bin/bash

#remove if the merged file exists (to avoid apppending to the same)
[ -e  EBAlignmentCoefficients_merged.txt ] && rm EBAlignmentCoefficients_merged.txt 
[ -e  EBAlignmentCoefficients_merged_wErr.txt ] && rm EBAlignmentCoefficients_merged_wErr.txt

#merge EB alignment txt files

for i in {0..35}
do
    cat EBAlignmentCoefficients_${i}.txt >> EBAlignmentCoefficients_merged.txt 
    cat EBAlignmentCoefficients_${i}.txt.bis >> EBAlignmentCoefficients_merged_wErr.txt
done   
echo "EB alignment coefficient txt files merged!"

[ -e  EEAlignmentCoefficients_merged.txt ] && rm EEAlignmentCoefficients_merged.txt 
[ -e  EEAlignmentCoefficients_merged_wErr.txt ] && rm EEAlignmentCoefficients_merged_wErr.txt

#merge EE alignment txt files
for i in {0..3}
do
    cat EEAlignmentCoefficients_${i}.txt >> EEAlignmentCoefficients_merged.txt
    cat EEAlignmentCoefficients_${i}.txt.bis >> EEAlignmentCoefficients_merged_wErr.txt
done
echo "EE alignment coefficient txt files merged!"
