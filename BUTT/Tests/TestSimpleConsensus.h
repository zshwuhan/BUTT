#ifndef TESTSIMPLECONSENSUS_H
#define TESTSIMPLECONSENSUS_H

#include "TestHelper.h"

class TestSimpleConsensus
{
public:
    TestSimpleConsensus();

   bool runTests();

    /**
     * Tests that no consensus at all returns empty taxonomy string.
     *
     * Input:    (("K#a")
     *            ("K#x"))
     *
     * Expected: "K#;P#;C#;O#;F#;G#;S#"
     */
    bool testSearchNodes1();

    /**
     * Tests consensus of perfect hit.
     *
     * Input:    (("K#a_1", "P#b_1", "C#c_1"),
     *            ("K#a_1", "P#b_1", "C#c_1"))
     *
     * Expected: "K#a_1;P#b_1;C#c_1;O#;F#;G#;S#"
     */
    bool testSearchNodes2();

    /**
     * Tests consensus of hit down to C-level: first word OK, second word bad.
     *
     * Input:    (("K#a_1", "P#b_1", "C#c_1"),
     *            ("K#a_1", "P#b_1", "C#c_2"))
     *
     * Expected: "K#a_1;P#b_1;C#c;O#;F#;G#;S#"
     */
    bool testSearchNodes3();

    /**
     * Tests consensus of hit down to P-level: first word OK, second word OK.
     *
     * Input:    (("K#a_1", "P#b_1", "C#c_1"),
     *            ("K#a_1", "P#b_1", "C#x_2"))
     *
     * Expected: "K#a_1;P#b_1;C#;O#;F#;G#;S#"
     */
    bool testSearchNodes4();

    /**
     * Tests consensus of hit down to P-level: first word OK, second word bad.
     *
     * Input:    (("K#a_1", "P#b_1", "C#c_1"),
     *            ("K#a_1", "P#b_2", "C#x_2"))
     *
     * Expected: "K#a_1;P#b;C#;O#;F#;G#;S#"
     */
    bool testSearchNodes5();

    /**
     * Tests consensus of hit down to K-level, first word OK, second word OK.
     *
     * Input:    (("K#a_1", "P#b_1", "C#c_1"),
     *            ("K#a_1", "P#x_2", "C#x_2"))
     *
     * Expected: "K#a_1;P#;C#;O#;F#;G#;S#"
     */
    bool testSearchNodes6();

    /**
     * Tests consensus of hit down to K-level, first word OK, second word bad.
     *
     * Input:    (("K#a_1", "P#b_1", "C#c_1"),
     *            ("K#a_2", "P#x_2", "C#x_2"))
     *
     * Expected: "K#a;P#;C#;O#;F#;G#;S#"
     */
    bool testSearchNodes7();
};

#endif // TESTSIMPLECONSENSUS_H