'''
Formula for area of circle
Area = pi * r^2
 where pi is constant and r is the radius of the circle
'''
def findarea(r):
	PI = 3.142
	return PI * (r * r)

if __name__ == "__main__":
	print("Area is %.6f" % findarea(5))
