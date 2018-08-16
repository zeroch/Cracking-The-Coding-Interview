class HashHeap(object):
	"""docstring for HashHeap"""
	# lets start it from max self.heap, and only integer 
	heap = []
	size = 0
	hashmap = dict()

	# in the hash self.heap, we need a self.heap to maintain max value
	# we need a self.hashmap to keep tracking location of each item
	# why?
	# in a self.heap, 
	# find operation is O(n)
	# insert opeartion is O(logn)
	# remove top operation is O(logn)
	# so when we try to remove certain target, it is O(n) + O(logn) => O(n)
	# use a hash map, we can directly find in O(1) and swap with the top one,
	# then remove with O(logn)

	def __init__(self):
		super(HashHeap, self).__init__()
		self.heap = []
		self.hashmap = dict()
		self.size = 0

	def __str__(self):
		heapString = ""
		for x in self.heap:
			valueString = '{0} '.format(x)
			heapString += valueString
		return heapString
	# swap function
	def _swap(self, left, right):
		# swap two object in the self.heap,
		# since these two value swap index
		# we need to swap "value" in the self.hashmap
		oldLeftValue, oldRightValue = self.heap[left], self.heap[right]
		# self.heap
		self.heap[left], self.heap[right] = self.heap[right], self.heap[left]
		# self.hashmap
		self.hashmap[oldLeftValue], self.hashmap[oldRightValue] = right, left

	def _sift_up(self, root):
		# if exist a parent
		while root!= 0:
			parent = (root -1) //2
			# if parent smaller than root
			# bubble up
			if self.heap[parent] < self.heap[root]:
				self._swap(parent, root)
			else:
				break
			root = parent

	def _sift_down(self, root):
		larger = root
		while root < self.size:
			left = root *2 +1
			right = root *2 +2

			# check left an right
			if left < self.size and self.heap[left] > self.heap[larger]:
				larger = left
			if right < self.size and self.heap[right] > self.heap[larger]:
				larger = right
			# we hit to end
			if larger != root:
				self._swap(larger, root)
			else:
				break
			root = larger

	# new insert value k, will add to self.size position
	# then we bubble up to where it should sit
	def push(self, k):
		self.heap.append(k)
		self.size += 1
		self.hashmap[k] = self.size -1
		self._sift_up(self.size -1)

	def top(self):
		return self.heap[0]
	
	def pop(self):
		# swap self.heap[0] and self.heap[-1]
		# delete hash[self.heap[-1]]
		# delete self.heap[-1]
		# bubble down self.heap[0]
		self._swap(0, self.size -1)

		lastItem = self.heap[self.size -1]
		del self.hashmap[lastItem]
		self.heap.pop()
		self.size -=1

		self._sift_down(0)

	def remove(self, k):
		if k not in self.hashmap:
			return
		# remove value K from Hashheap
		# find index of value k from self.heap
		# swap k with last object
		# delete k "new last object" from hash and self.heap
		# bubble down new value from (old k index)
		objIndex = self.hashmap[k]
		print('removing: {0}  and located at : {1}', k, objIndex)
		self._swap(objIndex, self.size-1)

		del self.hashmap[k]
		self.heap.pop()
		self.size -=1

		if objIndex < self.size:
			self._sift_up(objIndex)
			self._sift_down(objIndex)

	# self.heapify
	def heapify(self):
		for x in range(self.size//2, -1, -1):
			self._sift_down(x)


def main():
	print("hello")
	hashHeap = HashHeap()
	hashHeap.push(3)
	hashHeap.push(5)
	hashHeap.push(1)
	hashHeap.push(9)
	hashHeap.push(4)
	hashHeap.push(0)
	print(hashHeap)
	hashHeap.push(11)
	print(hashHeap)
	print(hashHeap.top())

	hashHeap.remove(1)
	print(hashHeap)
	print(hashHeap.top())
	hashHeap.pop()
	print(hashHeap)
	print(hashHeap.top())


if __name__ == "__main__" : main()
