import math

# Stand Behind Braum Solution
# UTSCode 2017
# Not for public eyes
# @Author: Brian Chen

def damageCalc(inc, res):
    # Reduction fraction
    reduc = (100 / (100 + res))
    dmg = inc * reduc
    return dmg

if __name__ == '__main__':
    # Parse input lines
    firstLine = raw_input()
    fl_items = firstLine.split()
    # Percentages
    phys = float(fl_items[0])
    mgc = float(fl_items[1])
    tru = float(fl_items[2])
    # Total Damage
    tot = float(fl_items[3])
    
    # Parse input lines
    secondLine = raw_input()
    sl_items = secondLine.split()
    # Resistances
    arm = float(sl_items[0])
    mr = float(sl_items[1])
    
    # Incoming damage calculations
    physDmg = phys * tot
    mgcDmg = mgc * tot
    truDmg = tru * tot
    
    # Totalling all the taken damage
    dmgTaken = truDmg
    dmgTaken += damageCalc(physDmg, arm)
    dmgTaken += damageCalc(mgcDmg, mr)
    dmgTaken = math.floor(dmgTaken)
    
    print(int(dmgTaken))