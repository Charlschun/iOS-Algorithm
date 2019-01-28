def twoSum(nums, target):
    kvs = {}
    for i, num in enumerate(nums):
        t = target - num
        if t in kvs:
            #find
            return [kvs[t], i]
        else:
            kvs[num] = i

if __name__ == '__main__':
    nums = [2, 7, 9, 13]
    result = twoSum(nums, 11)
    print("%s" % result)