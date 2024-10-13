import os
import sys
import csv
import pandas as pd

file_name = "../GameDataTable/CLGameplayTags"

#Xlsx to CSV
df = pd.read_excel(file_name+".xlsx", engine="openpyxl", header = 3)
print (df)

os.system('python DataImporter.py '+file_name)