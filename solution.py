from fractions import Fraction 
 
def solution(arr):
    N = len(arr)
    if ((not arr) or N == 1):
        return [-1,-1]
    parity = True if (N % 2 == 0) else False
    sum = (- arr[0] + arr[N - 1]) if parity else (- arr[0] - arr[N -1])
    if (N > 2):
        for idx in range(1, N-1):
            sum += 2 * (-1)**(idx+1) * arr[idx]
    r = Fraction(2 * (float(sum)/3 if parity else sum)).limit_denominator()
    if r < 2:
        return [-1,-1]
    currentRadius = r
    for idx in range(0, N-2):
        CenterDistance = arr[idx+1] - arr[idx]
        NextRadius = CenterDistance - currentRadius
        if (currentRadius < 1 or NextRadius < 1):
            return [-1,-1]
        else:
            currentRadius = NextRadius
    return [r.numerator, r.denominator]

if __name__ == "__main__":
    print(Fraction(5 , 2) * Fraction(2, 3))
