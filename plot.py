from plotly.graph_objs import *
import pprint
import csv
import plotly.plotly as py
import numpy as np

def create_data_lists():
    for x in range(0,100):
        with open(str(x)+'.csv', 'r') as f:
            print str(x)+' csv open'
            rowdata = []
            csvreader = csv.reader(f)
            for row in csvreader:
                rowdata.append(row)
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
