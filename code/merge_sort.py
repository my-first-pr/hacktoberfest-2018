def merge(a, l, m, r):
    """Merges 2 subarrays of a[]:
    First subarray is a[l..m]
    Second subarray is a[m+1..r]."""
    n1 = int(m - l + 1) # number of elements in left subarray
    n2 = int(r - m)     # number of elements in right subarray

    L, R = [], []   # create left and right subarrays (temp arrays)

    # copy data to temp arrays
    for i in range(n1):
        L.append(a[l+i])

    for j in range(n2):
        R.append(a[m+1+j])

    i, j = 0, 0 # initial index of left and right subarrays
    k = l       # initial index of merged subarray

    # merge the temp arrays back into a[]
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
        k += 1

    # copy the remaining elements of L[], if there are any
    while i < n1:
        a[k] = L[i]
        i += 1
        k += 1

    # copy the remaining elements of R[], if there are any
    while j < n2:
        a[k] = R[j]
        j += 1
        k += 1


def merge_sort(a, l, r):
    if l < r:
        m = (l+(r-1))//2      # get middle element
        merge_sort(a, l, m)   # sort left half
        merge_sort(a, m+1, r) # sort right half
        merge(a, l, m, r)     # merge the 2 halves


if __name__ == '__main__':
    a = [5, 7, -29, 0, 178, 2, 4, 11, -2, 6, -9]
    print("Original array: ", a)
    merge_sort(a, 0, len(a)-1)
    print("Sorted array: ", a)
