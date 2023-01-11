def hasAllCodes( s, k):
    reqCombination=pow(2,k)
    combinations=[]
    separateString=""
    while(s != None):
        if(len(s) > k):
            separateString=s[:k]
            s=s[k:]
        else:    
            separateString=s
            s=None
        if separateString not in combinations:
            combinations.append(separateString)
    if(len(combinations) == reqCombination):
        return True
    return False
print(hasAllCodes('00110',2))
