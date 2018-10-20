import random

def insertion_sort(A):
    for i in range(1, len(A)):
        for j in range(i, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
            else:
                break

if __name__ == '__main__':
    a = [random.randint(0,100) for k in range(20)]
    insertion_sort(a)
    print(a)
