void plot_hist_poisson() {
    // Open the data file
    std::ifstream inFile("histpoi.txt");
    if (!inFile) {
        std::cerr << "Error: Could not open file histpoi.txt" << std::endl;
        return;
    }

    // Create histogram
    TH1F *hist = new TH1F("histpoisson", "Poisson Expectation Histogram;X;Expectation Value", 11, -0.5, 10.5);

    // Skip the header line
    std::string header;
    std::getline(inFile, header);

    // Read data from the file and fill the histogram
    int X;
    double expectationValue;
    while (inFile >> X >> expectationValue) {
        hist->SetBinContent(X + 1, expectationValue); // ROOT bins start at 1
    }
    inFile.close();

    // Draw the histogram
    TCanvas *c1 = new TCanvas("c1", "Poisson Histogram", 800, 600);
    hist->SetFillColor(kBlue - 9);  // Set fill color
    hist->Draw("HIST");

    // Save the histogram to a file
    c1->SaveAs("histpoi.png");
}
