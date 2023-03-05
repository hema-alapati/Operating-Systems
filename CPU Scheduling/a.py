def replaceElements(arr):
        length = len(arr)
        result = []
        max_so_far = -999999
        for i in range(length-1, 0, -1):
            ele = arr[i]
            print(ele)
            if max_so_far < ele:
                max_so_far = ele
            result.insert(0, max_so_far)
        result.append(-1)
        return result

print(replaceElements(arr = [17,18,5,4,6,1]))