text = "X-DSPAM-Confidence:    0.8475"
fnum = text[text.find('0'):(len(text))+1]
fnum = float(fnum)
print(fnum)