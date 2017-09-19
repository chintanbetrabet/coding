import random
def dieceOutput(probs):
    simul=random.random()
    subsum=[probs[0]]
    for i in range(1,len(probs)):
        subsum.append(subsum[i-1]+probs[i])
    for i in range(len(probs)):
        if simul < subsum[i]:
            return i+1
probs=map(float,raw_input().split(','))
dieceOutput(probs)
