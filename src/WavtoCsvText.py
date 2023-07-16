import sys, os, os.path
from scipy.io import wavfile
import pandas as pd

input_filename = input("Wav file path: ")
if input_filename[-4:] != '.wav':
    print('File format error, expected wav file')
    sys.exit()

sampleRate, fileData = wavfile.read(str(input_filename))

divideConst = 1
if fileData.dtype == 'int32':
  divideConst = 2147483648
elif fileData.dtype == 'int16':
  divideConst = 32768

data = fileData / divideConst

wavFileData = pd.DataFrame(data)


if len(wavFileData.columns) == 2:
    wavFileData.columns = ['R', 'L']
    R_channel = pd.DataFrame(wavFileData['R'])
    L_channel = pd.DataFrame(wavFileData['L'])
    result = pd.concat([L_channel, R_channel], axis=1)
    result.to_csv(r'stero.txt', header=None, index=None, sep=' ', mode='a')
elif len(wavFileData.columns) == 1:
    wavFileData.columns = ['M']
    result = pd.DataFrame(wavFileData['M'])
    result.to_csv(r'mono.txt', header=None, index=None, sep=' ', mode='a')
else:
    print('error: Process is only avalible for mono or stereo wav files.')
    sys.exit()