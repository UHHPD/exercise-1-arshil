
void plot_hist() {
    // Open the file
    std::ifstream infile("hist.txt");
    if (!infile) {
        std::cerr << "File not found!" << std::endl;
        return;
    }

    // Define variables to hold the values
    int bin;
    int freq;

    // Create a histogram
    TH1F *hist = new TH1F("hist", "Histogram from hist.txt", 20, 0, 20); // Adjust bins and range as needed

    // Read data from the file and fill the histogram
    while (infile >> bin >> freq) {
        for (int i = 0; i < freq; ++i) { // Fill the histogram with the frequency
            hist->Fill(bin);
        }
    }

    // Close the file
    infile.close();

    // Draw the histogram
    TCanvas *c1 = new TCanvas("c1", "Histogram", 800, 600);
    hist->Draw();

    // Save the histogram
    c1->SaveAs("histogram.png"); // Save as PNG, adjust format as needed
}
