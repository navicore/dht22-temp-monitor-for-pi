package onextent.iot.dht22

import ch.jodersky.jni.nativeLoader

@nativeLoader("dht220")
class Dht22 {
  // --- Native methods
  @native def intMethod(n: Int): Int
  @native def booleanMethod(b: Boolean): Boolean
  @native def stringMethod(s: String): String
  @native def intArrayMethod(a: Array[Int]): Int
}

