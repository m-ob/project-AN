import matplotlib.pyplot as plt
import numpy as np
import re
import matplotlib.patches as mpatches
from matplotlib.legend_handler import HandlerLine2D
IJ = []
JI = []
IJK = []
JIK = []
IKJ = []
JKI = []
KIJ = []
KJI = []

mIJ = [[0 for x in range(7)] for y in range(6)]
mbIJ = [[0 for x in range(7)] for y in range(6)] 

mJI = [[0 for x in range(7)] for y in range(6)]
mbJI = [[0 for x in range(7)] for y in range(6)] 

mIJK = [[0 for x in range(7)] for y in range(6)]
mbIJK = [[0 for x in range(7)] for y in range(6)] 

mJIK = [[0 for x in range(7)] for y in range(6)]
mbJIK = [[0 for x in range(7)] for y in range(6)] 

mIKJ = [[0 for x in range(7)] for y in range(6)]
mbIKJ = [[0 for x in range(7)] for y in range(6)]

mJKI = [[0 for x in range(7)] for y in range(6)]
mbJKI = [[0 for x in range(7)] for y in range(6)] 

mKIJ = [[0 for x in range(7)] for y in range(6)]
mbKIJ = [[0 for x in range(7)] for y in range(6)]

mKJI = [[0 for x in range(7)] for y in range(6)]
mbKJI = [[0 for x in range(7)] for y in range(6)] 

Pile = [mIJK[5], mJIK[5], mIKJ[5], mJKI[5], mKIJ[5], mKJI[5]]
GoperPile = [mbIJK[5], mbJIK[5], mbIKJ[5], mbJKI[5], mbKIJ[5], mbKJI[5]]
NamePileList = ['IJK','JIK','IKJ','JKI','KIJ','KJI']
NamePile = 'IJK-JIK-IKJ-JKI-KIJ-KJI'
markers = ["o","s","p","P","D","X"]



with open('IJ.txt') as f:
  IJ = re.findall('\d*?\.\d+', f.read())
  for i in range(84):
      IJ[i] = float(IJ[i])


with open('JI.txt') as f:
  JI = re.findall('\d*?\.\d+', f.read())
  for i in range(84):
      JI[i] = float(JI[i])


with open('IJK.txt') as f:
  IJK = re.findall('\d*?\.\d+', f.read())
  for i in range(84):
      IJK[i] = float(IJK[i])

with open('JIK.txt') as f:
  JIK = re.findall('\d*?\.\d+', f.read())
  for i in range(84):
      JIK[i] = float(JIK[i])


with open('IKJ.txt') as f:
  IKJ = re.findall('\d*?\.\d+', f.read())
  for i in range(84):
      IKJ[i] = float(IKJ[i])

with open('JKI.txt') as f:
  JKI = re.findall('\d*?\.\d+', f.read())
  for i in range(84):
      JKI[i] = float(JKI[i])


with open('KIJ.txt') as f:
  KIJ = re.findall('\d*?\.\d+', f.read())
  for i in range(84):
      KIJ[i] = float(KIJ[i])

with open('KJI.txt') as f:
  KJI = re.findall('\d*?\.\d+', f.read())
  for i in range(84):
      KJI[i] = float(KJI[i])

x = 0
for i in range(6):
	for j in range(7):
		mIJ[i][j] = IJ[x]
		mJI[i][j] = JI[x]
		mIJK[i][j] = IJK[x] 
		mJIK[i][j] = JIK[x] 
		mIKJ[i][j] = IKJ[x] 
		mJKI[i][j] = JKI[x] 
		mKIJ[i][j] = KIJ[x] 
		mKJI[i][j] = KJI[x]
		
		mbIJ[i][j] = IJ[x+42]
		mbJI[i][j] = JI[x+42]
		mbIJK[i][j] = IJK[x+42] 
		mbJIK[i][j] = JIK[x+42] 
		mbIKJ[i][j] = IKJ[x+42] 
		mbJKI[i][j] = JKI[x+42] 
		mbKIJ[i][j] = KIJ[x+42] 
		mbKJI[i][j] = KJI[x+42] 
		x = x + 1

xAxis = [100, 200, 400, 500, 800, 1000, 2000]

def findmax(x):
	max = 0
	for i in range(6):
		for j in range(7):
			if (x[i][j] > max):
				max = x[i][j]
	return max

def findmaxLine(x,y):
	max1 = 0
	max2 = 0
	for i in range(7):
		if (x[i] > max1):
			max1 = x[i]
		if (y[i] > max2):
			max2 = y[i]
	if max1 < max2:
		max1 = max2 
	return max1

def findmaxElem(x,y):
	max = 0
	for i in range(7):
		if (y[i] > max):
			max = y[i]
	if max < x:
		max = x 
	return max				 



def createPlotAdd(x):
	x.figure("addition de 2 matrices carrées de tailles n")
	x.subplot(1,2,1)
	x.axis([0, 2000, 0, findmaxLine(mIJ[5],mJI[5])])
	x.grid(True)
	x.title("IJ-JI float")
	x.xlabel("taille de matrice")
	x.ylabel("duree d'execution")
	x.plot(xAxis,mIJ[5],label = "IJ",marker = markers[0])
	x.plot(xAxis,mJI[5],label = "JI",marker = markers[1])
	x.legend()
	x.subplot(1,2,2)
	x.axis([0, 2000, 0, findmaxLine(mbIJ[5],mbJI[5])])
	x.grid(True)
	x.title("IJ-JI long double")
	x.xlabel("taille de matrice")
	x.ylabel("duree d'execution")
	x.plot(xAxis,mbIJ[5],label = "IJ",marker = markers[0])
	x.plot(xAxis,mbJI[5],label = "JI",marker = markers[1])
	x.legend()

	
def createPlotProd(x):
	x.figure("produit de 2 matrices carrées de tailles n")
	max = 0
	maxb = 0
	for i in range(6):
		max = findmaxElem(max,Pile[i])
		maxb = findmaxElem(maxb,GoperPile[i])

	x.subplot(1,2,1)
	x.axis([0, 1000, 0, max])
	x.grid(True)
	x.title(NamePile + " float")
	x.xlabel("taille de matrice")
	x.ylabel("duree d'execution")
	for i in range(6):
		x.plot(xAxis,Pile[i],label=NamePileList[i],marker = markers[i])
		x.legend()


	x.subplot(1,2,2)
	x.axis([0, 1000, 0, maxb])
	x.grid(True)
	x.title(NamePile + " long double")
	x.xlabel("taille de matrice")
	x.ylabel("duree d'execution")
	for i in range(6):
		x.plot(xAxis,GoperPile[i],label=NamePileList[i],marker = markers[i])
		x.legend()


Fplt = plt
Splt = plt
createPlotAdd(Fplt)
createPlotProd(Splt)
Fplt.show()
Splt.show()