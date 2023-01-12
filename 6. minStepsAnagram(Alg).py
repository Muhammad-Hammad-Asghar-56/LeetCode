# You are given two strings s and t. In one step, you can append any character to either s or t.
# Return the minimum number of steps to make s and t anagrams of each other.
# An anagram of a string is a string that contains the same characters with a different (or the same) ordering.


#                                   Itrative Method
def minIterSteps(s, t):
    steps=0
    firstLtr=s
    secondLtr=t
    for i in firstLtr:
        if(i not in secondLtr):
            steps=steps+1
            continue
        secondLtr=list(secondLtr)
        secondLtr.remove(i)
        secondLtr=''.join(secondLtr)
    firstLtr=s
    secondLtr=t
    for i in secondLtr:
        if(i not in firstLtr):
            steps=steps+1
            continue
        firstLtr=list(firstLtr)
        firstLtr.remove(i)
        firstLtr=''.join(firstLtr)
    return steps
#                                  Recursive Method
def minRecSteps(s, t):
    if(s==t):
        return 0
    elif(s == ''):
        return len(t)
    elif (t == ''):
        return len(s)
    else:
        s=list(s)
        isPresentChr=s[0]
        if(not isPresentChr  in t): 
            return 1 + minRecSteps(''.join(s[1:]),t)
        else:
            t=list(t)
            t.remove(isPresentChr)
            t=''.join(t)
            return minRecSteps(''.join(s[1:]),t)
print(minRecSteps('IKHmad','Hmad'))