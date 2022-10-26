import sys
import os

verbose = 0
os.system("cmsenv")

### get EB, EE alignment tag names from GT

command = "conddb list " + sys.argv[1] + " | grep \"EBAlignmentRcd\|EEAlignmentRcd\""    #conddb list 124X_dataRun3_Prompt_v4 | grep "EBAlignmentRcd\|EEAlignmentRcd"
if verbose: print command
read_tags = os.popen(command)         
tagNames = read_tags.readlines()

for i, tag_ in enumerate(tagNames):
    tag_.strip()
    align_tag = tag_.split()
    if verbose: 
        print align_tag
        print "tag name: ", align_tag[2]
    
    ### get the latest iov for each tag

    command = "conddb list " + align_tag[2]
    if verbose: print command
    read_iovs = os.popen(command)
    iovs =  read_iovs.readlines()
    iovs[-2].strip()
    latest_iov = iovs[-2].split()

    ### dump content

    command = "conddb dump " + list(latest_iov)[3]
    if verbose: print command
    dump = os.popen(command)
    lines = dump.readlines()

    dx = []
    dy = []
    dz = []
    dphi = []
    dtheta = []
    dpsi = []

    ### get dphi, dtheta, dpsi, dx, dy, dz values

    for j, line in enumerate (lines):
        l = line.strip()
        if(l.startswith("<dx>")):
            dx.append(float(l[4:-5]))
        elif(l.startswith("<dy>")):
            dy.append(float(l[4:-5]))
        elif(l.startswith("<dz>")):
            dz.append(float(l[4:-5]))
        elif(l.startswith("<phi_>")):
            dphi.append(float(l[6:-7]))
        elif(l.startswith("<theta_>")):
            dtheta.append(float(l[8:-9]))
        elif(l.startswith("<psi_>")):
            dpsi.append(float(l[6:-7]))

    ### write to a txt file

    if (i == 0):
        outFile = open('EB_alignment_coeff_old.txt','w')
        for sm in range(len(dx)):
            outFile.write(str(dphi[sm]) + '\t' + str(dtheta[sm]) + '\t' + str(dpsi[sm]) + '\t' + str(dx[sm]) + '\t' + str(dy[sm])+ '\t' + str(dz[sm]) + '\n' )
        print "\nGenerated", outFile.name, '\n'
    
    if (i == 1):
        outFile = open('EE_alignment_coeff_old.txt','w')
        for sm in range(len(dx)):
            outFile.write(str(dphi[sm]) + '\t' + str(dtheta[sm]) + '\t' + str(dpsi[sm]) + '\t' + str(dx[sm]) + '\t' + str(dy[sm])+ '\t' + str(dz[sm]) + '\n' )
        print "\nGenerated", outFile.name, '\n'

        
    if (verbose):
        print("dx = ", dx)
        print("dy = ", dy)
        print("dz = ", dz)
        print("dphi = ", dphi)
        print("dtheta = ", dtheta)
        print("dpsi = ", dpsi)