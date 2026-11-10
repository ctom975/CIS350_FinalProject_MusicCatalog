# CIS350_FinalProject_MusicCatalog
Organize instrument families, compositions and instrument requirements.

## Dataset Format & Modifications

The dataset used in this project was originally formatted as folders with audio excerpts in the WAV format, and text files for each excerpt with a unique code representing different instruments:

| Code | Instrument          |
|------|---------------------|
| cel  | cello               |
| cla  | clarinet            |
| flu  | flute               |
| gac  | acoustic guitar     |
| gel  | electric guitar     |
| org  | organ               |
| pia  | piano               |
| sax  | saxophone           |
| tru  | trumpet             |
| vio  | violin              |
| voi  | human singing voice |

The dataset was modified to remove the WAV audio excerpts, and combine all text files into individual CSV files based on the following input sizes:

- 100
- 250
- 500
- 1000
- 2000
- Full (2874)

## Acknowledgements

The dataset used in this project ([IRMAS](https://www.upf.edu/web/mtg/irmas)) was created by Juan J. Bosch, Ferdinand Fuhrmann, Perfecto Herrera, and is licensed under [Creative Commons Attribution-NonCommercial-NoDerivs 3.0 Spain](https://creativecommons.org/licenses/by-nc-nd/3.0/es/deed.en).

```
Bosch, J. J., Janer, J., Fuhrmann, F., & Herrera, P. “A Comparison of Sound Segregation Techniques for Predominant Instrument Recognition in Musical Audio Signals”, in Proc. ISMIR (pp. 559-564), 2012
```