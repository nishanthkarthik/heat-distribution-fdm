from plotly.graph_objs import *
import pprint
import csv
import plotly.plotly as py
import numpy as np

def create_data_lists():
    n = 50
    for x in range(0,1):
        with open(str(x)+'.csv', 'r') as f:
            print str(x)+' csv open'
            rowdata = []
            csvreader = csv.reader(f)
            #csvreader.next()
            for row in csvreader:
                itemlist = []
                for item in row:
                    itemlist.append(float(item))
                rowdata.append(itemlist)
            #pprint.pprint(rowdata)
            #print rowdata.__class__
            print str(x) + " data collected"
            data = Data([Heatmap(z = rowdata)])
            print str(x) + " image starting"
            py.image.save_as({'data': data}, str(x)+'.png')
            print str(x) + " image saved"

def main():
    create_data_lists()

if __name__ == "__main__":
    main()
