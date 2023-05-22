(
z = {
	var freq , amp, sig;
	freq = LFNoise0.kr(10).exprange(200,500);
	amp = LFNoise1.kr(500).exprange(0.5,1.0);
	sig = SinOsc.ar(freq) * amp;
}.play;
)

z.set(\noiseHZ,64);
z.set(\noiseHZ, exprand(4,64));
z.free;


