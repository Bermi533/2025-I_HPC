#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atof(argv[1]);
  const int NSAMPLES = std::atof(argv[2]);
  const double MU = std::atof(argv[3]);
  const double SIGMA = std::atof(argv[4]);
  const double XMIN = std::atof(argv[5]);
  const double XMAX = std::atof(argv[6]);
  const int NBINS = std::atof(argv[7]);

  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};
  // TODO: histogram stuff
  std::vector<int> samples(nbins,0);
  double ancho = (xmax - xmin)/nbins;

  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);
    // TODO: fill here the counting histogram stuff
    if(r >= xmin || r < xmax) {
        int caja = int(((r-xmin)/(ancho)));
        if(caja >=0 || caja < nbins)
        ++samples[caja];
    }

  }
  // TODO: compute and print the pdf

    std::cout << std::fixed << std::setprecision(7);
    for(int i = 0; i < nbins; ++i) {
        double xcen = xmin + (i + 0.5) * ancho;
        double pdf = double(samples[i]) / (nsamples * ancho);
        std::cout << xcen << "  " << pdf << "\n";
    }

}
