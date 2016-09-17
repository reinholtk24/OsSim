/*#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "command.hpp"
#include "commandHandler.h"
#include "pcbcommandhandler.h"
#include "pcb.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

PCBCommandHandler pcbTester;
PCB pcbD;

TEST_CASE( "Get Max Memory Test", "[PCB Command]" ) {
    REQUIRE(  pcbTester.getMaxMemory() == 2000000000 );
}

TEST_CASE( "Random PCB memory test", "[PCB Command]" ) {
    REQUIRE(  pcbD.getMemory() < 10000 );
}

TEST_CASE( "PCB PID test", "[PCB Command]" ) {
    REQUIRE(  pcbD.getPID() == 0 );
}

TEST_CASE( "PCB IO test", "[PCB Command]" ) {
    REQUIRE(  pcbD.getIO() == 0 );
}

TEST_CASE( "PCB Wait test", "[PCB Command]" ) {
    REQUIRE(  pcbD.getWait() == 0 );
}

TEST_CASE( "PCB cpu test", "[PCB Command]" ) {
    REQUIRE(  pcbD.getCPU() == 0 );
}



/*
CommandDictionary myDictionary;
CommandHandler myCommands;

TEST_CASE( "Test version Command", "[Child Commands]" ) {
    versionCommand version;
    version.setVersion("Version: 1.0");
    REQUIRE(  version.getVersion() == "Version: 1.0" );
    REQUIRE(  version.execute() == true);
}

TEST_CASE( "Test date Command", "[Child Commands]" ) {
    dateCommand date;
    REQUIRE(  date.execute() == true );
}

TEST_CASE( "Test history Command", "[Child Commands]" ) {
    historyCommand history;
    REQUIRE(  history.execute() == true );
}

TEST_CASE( "Test alias Command", "[Child Commands]" ) {
    aliasCommand alias;
    REQUIRE(  alias.execute() == true );
}

TEST_CASE( "Test help Command", "[Child Commands]" ) {
    helpCommand help;
    REQUIRE(  help.execute() == true );
}

TEST_CASE( "Test quit Command", "[Child Commands]" ) {
    quitCommand quit;
    REQUIRE(  quit.execute() == false );
}

TEST_CASE( "Test Command Dictionary", "[Command Dictionary]" ) {
    REQUIRE(  myDictionary.getCmdCode("date") == 0 );
    REQUIRE(  myDictionary.getCmdCode("version") == 1 );
    REQUIRE(  myDictionary.getCmdCode("help") == 2 );
    REQUIRE(  myDictionary.getCmdCode("directory") == 3 );
    REQUIRE(  myDictionary.getCmdCode("quit") == 4 );
    REQUIRE(  myDictionary.getCmdCode("history") == 5 );
    REQUIRE(  myDictionary.getCmdCode("alias") == 6 );
    REQUIRE(  myDictionary.getCmdCode("batch") == 7 );
}


TEST_CASE( "Test Command Handler", "[Command Handler]" ) {
    REQUIRE(  myCommands.executeCommand("date") == 1 );
    REQUIRE(  myCommands.executeCommand("version") == 1 );
    REQUIRE(  myCommands.executeCommand("help") == 1 );
    REQUIRE(  myCommands.executeCommand("directory") == 1 );
    REQUIRE(  myCommands.executeCommand("quit") == 0 );
    REQUIRE(  myCommands.executeCommand("history") == 1 );
    REQUIRE(  myCommands.executeCommand("alias quit exit") == 1 );
    REQUIRE(  myCommands.executeCommand("batch commands.sh") == 1 );
}
*/

