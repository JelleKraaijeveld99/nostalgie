
// s.meter
//
// (
// SynthDef.new(\multi, {
// 	var sig,amp;
// 	amp = SinOsc.kr({ExpRand(0.2,12)}!8).range(0.1);
// 	sig = SinOsc.ar({ExpRand(50,1200)}!8);
// 	sig = sig * amp;
// 	sig = Splay.ar(sig) * 0.5;
// 	Out.ar(0,sig);
// }).add;
//
// x = Synth.new(\multi);
// x.free;

(
~fn = {
	arg amp = 0.2;
	var sig, mod;
	mod= SinOsc.kr(freq: 1/4, phase: 3pi/2).range(0,1);
	sig = PinkNoise.ar(amp ! 2);
	sig = sig * mod;
};
)

x = ~fn.play;
x.release(5);

(
~fn = {
	arg modWith = 200;
	var sig, mod;
	mod= SinOsc.kr(freq: 5).bipolar(modWith);
	sig = SinOsc.ar(300 + mod, mul: 0.1);
	sig !2;
};
)

x = ~fn.play;
x.release(5);
x.set(\modWith, 300);





