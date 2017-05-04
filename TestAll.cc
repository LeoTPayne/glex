#include <cppunit/ui/text/TestRunner.h>

#include "Testboundingbox.h"

int main( int argc, char **argv) {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( Testboundingbox::suite() );
  runner.run();
  return 0;
}
