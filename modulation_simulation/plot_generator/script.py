import sys
import csv
import os
import matplotlib.pyplot as plt

def main():
    if len(sys.argv) != 2:
        print("Usage: python plot_constellation.py <file.csv>")
        sys.exit(1)

    filename = sys.argv[1]

    I, Q = [], []
    with open(filename, newline="") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            I.append(float(row["I"]))
            Q.append(float(row["Q"]))

    fig, ax = plt.subplots(figsize=(6, 6))
    ax.scatter(I, Q, s=30)

    ax.axhline(0.0, linewidth=1.2)
    ax.axvline(0.0, linewidth=1.2)

    max_abs = max(max(abs(x) for x in I), max(abs(y) for y in Q), 1e-6)
    lim = max_abs * 1.15
    ax.set_xlim(-lim, lim)
    ax.set_ylim(-lim, lim)

    ax.set_xlabel("I")
    ax.set_ylabel("Q")
    ax.set_title(f"Constellation plot: {os.path.basename(filename)}")
    ax.grid(True)
    ax.set_aspect("equal", adjustable="box")

    output_file = os.path.splitext(filename)[0] + ".png"
    fig.savefig(output_file, dpi=200, bbox_inches="tight")
    plt.close(fig)

    print(f"Plot saved to {output_file}")


if __name__ == "__main__":
    main()
