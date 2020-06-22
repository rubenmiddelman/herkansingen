#include <iostream>
#include "jack_module.h"
#include "math.h"
#include "Synth.h"
#include "sine.h"
#include "Osc.h"

Synth::Synth(float samplerate)
{
  std::cout << "Synth - constructor\n";
}


Synth::~Synth()
{
  std::cout << "Synth - destructor\n";
}

int Synth::MainSynthFunc()
{
  JackModule jack;
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  Sine sine1(440, samplerate);
  Sine sine2(440, samplerate);

  jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
 for(unsigned int i = 0; i < nframes; i++) {
   outBuf[i] =sine1.getSample()*sine2.getSample();
   sine1.tick();
   sine2.tick();
   }
  return 0;
 };
 jack.autoConnect();
 return 0;

}
