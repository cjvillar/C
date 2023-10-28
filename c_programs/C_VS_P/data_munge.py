import argparse
import csv


def get_data(csv_file):
    with open(csv_file, "r", newline="") as csvfile:
        csvreader = csv.DictReader(csvfile)
        header = next(csvreader)
        [print(k) for k in header.keys()]
        [(row) for row in csvreader]
       
        

    
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Reads headers and data points")
    parser.add_argument(
        "csv_file",
        type=str,
        default=50,
        help="The CSV file",
    )
    args = parser.parse_args()
    csv_file = args.csv_file
    get_data(csv_file)
