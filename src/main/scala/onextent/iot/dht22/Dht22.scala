package onextent.iot.dht22

import ch.jodersky.jni.nativeLoader

@nativeLoader("dht220")
class Dht22 {

  // --- Native methods
  @native def get(): Array[Float]

}

