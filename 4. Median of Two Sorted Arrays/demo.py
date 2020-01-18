nums = [1,2,3,4]
nums1 = [1,2]
nums2 = [3,4]
nums3 = nums1 + nums2
nums3.sort()
print(nums3)
print(type(nums))
print(len(nums))
l = len(nums3)
mid = (nums3[(l-1)//2]+nums3[l//2])/2
print(mid)