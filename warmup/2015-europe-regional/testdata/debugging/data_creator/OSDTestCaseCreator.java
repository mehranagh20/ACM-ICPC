import java.util.Collection;
import java.util.LinkedList;


public class OSDTestCaseCreator implements TestCaseCreator{
	
	public Collection<TestCase> createSamples(){
		Collection<TestCase> samples=new LinkedList<TestCase>();
		
		samples.add(sample1());
		samples.add(sample2());
		samples.add(sample3());
		
		return samples;
	}
	
	public Collection<TestCase> createWrong(){
		Collection<TestCase> samples=new LinkedList<TestCase>();
		
		samples.add(edgeCase001w());
		samples.add(edgeCase00_1w());
		samples.add(edgeCase010w());
		samples.add(edgeCase0_10w());
		samples.add(edgeCase100w());
		samples.add(edgeCase_100w());
		
		return samples;
	}
	

	
	public Collection<TestCase> createSecret(){
		Collection<TestCase> samples=new LinkedList<TestCase>();
		
		samples.add(needed7());
		samples.add(maximal());
		
		samples.add(edgeCase000());
		samples.add(edgeCase001());
		samples.add(edgeCase010());
		samples.add(edgeCase011());
		samples.add(edgeCase100());
		samples.add(edgeCase101());
		samples.add(edgeCase110());
		
		samples.add(twoLines());
		samples.add(twoLinesCostlyRun());
		samples.add(twoLinesCostlyTyping());
		

		samples.add(tenLinesEqual());
		samples.add(twelweLinesEqual());
		samples.add(thirteenLinesEqual());
		
		
		samples.add(nineLines());
		samples.add(nineLinesTypingHigher());
		samples.add(nineLinesRunSlightlyHigher());
		samples.add(nineLinesRunOveCritical());
		samples.add(nineLinesRunUnderCritical());

				
	
		
		
	//handmade part2:
		

		samples.add(unique973());
		samples.add(checkFor973());
		samples.add(unique3073());
		samples.add(typeAfterEveryLine());
		samples.add(max33());
		samples.add(min34());
		samples.add(max41());
		samples.add(min42());
		samples.add(differentTypedCount());
		samples.add(bigDiffManyTyped79508());
		samples.add(check79508());

		samples.add(biggerNumberOfLines439401());
		samples.add(check439401());	
		samples.add(biggerNumberOfLines194482());
		samples.add(check194482());
		samples.add(biggerNumberOfLines511759());
		samples.add(check511759());

		samples.add(long78733());
		samples.add(check78733());
		samples.add(long233281());
		samples.add(check233281());
		samples.add(prime7311());
		samples.add(checkPrime7311());
		
		samples.add(typingCostly());
		samples.add(checkTypingCostly());
		
		samples.add(timeOut1());
		samples.add(timeOut2());
		samples.add(timeOut3());
		samples.add(timeOut4());
		

		samples.add(need53());
		samples.add(need997());
		samples.add(need999());
		
		
		
		
		
	//Random test cases:
		OSDRandomFileCreator smallRandomCases=new OSDRandomFileCreator(22, 1000,100,100, "small");
		samples.addAll(smallRandomCases.createTestCases(3));

		OSDRandomFileCreator middleRandomCases=new OSDRandomFileCreator(222, 100_000,100_000,10_000, "middle");
		samples.addAll(middleRandomCases.createTestCases(3));


		OSDRandomFileCreator bigRandomCases=new OSDRandomFileCreator(2222, 1_000_000,1_000_000_000,100_000_000, "big");
		samples.addAll(bigRandomCases.createTestCases(4));
		
		return samples;
	}

	//samples: 
	
	private static TestCase sample1(){
		return new OSDTestCase(1, 100, 20, 0);
	}
	
	private static TestCase sample2(){
		return new OSDTestCase(10, 10, 1, 19);
	}
	
	private static TestCase sample3(){
		return new OSDTestCase(16, 1, 10, 44);
	}
	
	
	//wrong results:	
	private static OSDWrongTestCase edgeCase001w(){
		OSDWrongTestCase result=new OSDWrongTestCase(OSDTestCase.MIN_LINE_COUNT, OSDTestCase.MIN_RUNNING_TIME, OSDTestCase.MAX_TYPING_TIME+1);
		result.setTestName("w_edge001");
		return result;
	}
	
	private static OSDWrongTestCase edgeCase00_1w(){
		OSDWrongTestCase result=new OSDWrongTestCase(OSDTestCase.MIN_LINE_COUNT, OSDTestCase.MIN_RUNNING_TIME, OSDTestCase.MIN_TYPING_TIME-1);
		result.setTestName("w_edge00_1");
		return result;
	}
	
	private static OSDWrongTestCase edgeCase010w(){
		OSDWrongTestCase result=new OSDWrongTestCase(OSDTestCase.MIN_LINE_COUNT, OSDTestCase.MAX_RUNNING_TIME+1, OSDTestCase.MAX_TYPING_TIME);
		result.setTestName("w_edge010");
		return result;
	}
	
	private static OSDWrongTestCase edgeCase0_10w(){
		OSDWrongTestCase result=new OSDWrongTestCase(OSDTestCase.MIN_LINE_COUNT, OSDTestCase.MIN_RUNNING_TIME-1, OSDTestCase.MAX_TYPING_TIME);
		result.setTestName("w_edge0_10");
		return result;
	}
	
	private static OSDWrongTestCase edgeCase100w(){
		OSDWrongTestCase result=new OSDWrongTestCase(OSDTestCase.MAX_LINE_COUNT+1, OSDTestCase.MIN_RUNNING_TIME, OSDTestCase.MAX_TYPING_TIME);
		result.setTestName("w_edge010");
		return result;
	}
	
	private static OSDWrongTestCase edgeCase_100w(){
		OSDWrongTestCase result=new OSDWrongTestCase(OSDTestCase.MIN_LINE_COUNT-1, OSDTestCase.MIN_RUNNING_TIME, OSDTestCase.MAX_TYPING_TIME);
		result.setTestName("w_edge0_10");
		return result;
	}
	
	
	//secrets:

	
	private static TestCase needed7(){
		OSDTestCase result=new OSDTestCase(339, 7, 1);
		result.setTestName("need7");
		result.setDescription("7 steps needed");
		return result;
	}
	
	
	private static OSDTestCase edgeCase000(){
		OSDTestCase result=new OSDTestCase(OSDTestCase.MIN_LINE_COUNT, OSDTestCase.MIN_RUNNING_TIME, OSDTestCase.MIN_TYPING_TIME, 0);
		result.setTestName("edge000");
		result.setDescription("all value minimal");
		return result;
	}
	
	private static OSDTestCase edgeCase010(){
		OSDTestCase result=new OSDTestCase(OSDTestCase.MIN_LINE_COUNT, OSDTestCase.MAX_RUNNING_TIME, OSDTestCase.MIN_TYPING_TIME, 0);
		result.setTestName("edge010");
		result.setDescription("minimal values for all but running time");
		return result;
	}
	
	private static OSDTestCase edgeCase001(){
		OSDTestCase result=new OSDTestCase(OSDTestCase.MIN_LINE_COUNT, OSDTestCase.MIN_RUNNING_TIME, OSDTestCase.MAX_TYPING_TIME, 0);
		result.setTestName("edge010");
		result.setDescription("minimal values for all but typing time");
		return result;
	}
	
	private static OSDTestCase edgeCase011(){
		OSDTestCase result=new OSDTestCase(OSDTestCase.MIN_LINE_COUNT, OSDTestCase.MAX_RUNNING_TIME, OSDTestCase.MAX_TYPING_TIME, 0);
		result.setTestName("edge010");
		result.setDescription("max values for all but line count");
		return result;
	}	
	
	
	private static OSDTestCase edgeCase100(){
		OSDTestCase result=new OSDTestCase(OSDTestCase.MAX_LINE_COUNT, OSDTestCase.MIN_RUNNING_TIME, OSDTestCase.MIN_TYPING_TIME);
		result.setTestName("edge100");
		result.setDescription("min values for all but line count");
		return result;
	}
	
	
	private static OSDTestCase edgeCase101(){
		OSDTestCase result=new OSDTestCase(OSDTestCase.MAX_LINE_COUNT, OSDTestCase.MIN_RUNNING_TIME, OSDTestCase.MAX_TYPING_TIME);
		result.setTestName("edge101");
		result.setDescription("max values for all but running time");
		return result;
	}
	
	
	private static OSDTestCase edgeCase110(){
		OSDTestCase result=new OSDTestCase(OSDTestCase.MAX_LINE_COUNT, OSDTestCase.MAX_RUNNING_TIME, OSDTestCase.MIN_TYPING_TIME);
		result.setTestName("edge110");
		result.setDescription("max values for all but typing time");
		return result;
	}
	
		
	private static TestCase maximal(){
		OSDTestCase result=new OSDTestCase(OSDTestCase.MAX_LINE_COUNT, OSDTestCase.MAX_RUNNING_TIME, OSDTestCase.MAX_TYPING_TIME);
		result.setTestName("maximal");
		result.setDescription("the maximal possible values for all three arguments -> long as result");
		return result;
	}
	
	private static TestCase twoLines(){
		OSDTestCase result=new OSDTestCase(2, 200, 300, 500L);
		result.setTestName("twoLines");
		result.setDescription("only two Lines, best solution to put a printf in the middle no matter which costs");
		return result;
	}
	
	private static TestCase twoLinesCostlyRun(){
		OSDTestCase result=new OSDTestCase(2, 1_000_000_000, 300, 1_000_000_300L);
		result.setTestName("twoLinesCostlyRun");
		result.setDescription("only two Lines, best solution to put a printf in the middle no matter which costs (but the cost for the run is very high)");
		return result;
	}
	
	
	private static TestCase twoLinesCostlyTyping(){
		OSDTestCase result=new OSDTestCase(2, 3, 1_000_000_000, 1_000_000_003L);
		result.setTestName("twoLinesCostlyTyping");
		result.setDescription("only two Lines, best solution to put a printf in the middle no matter which costs (but the cost for the typing is very high)");
		return result;
	}
	
	
	private static TestCase threeLines(){
		OSDTestCase result=new OSDTestCase(3, 2, 2, 6L);
		result.setTestName("threeLines");
		result.setDescription("only three Lines, best solution to put a printf after each line and do only one run");
		return result;
	}
	
	
	
	private static TestCase threeLinesCostlyRun(){
		OSDTestCase result=new OSDTestCase(3, 1_000_000_000, 1, 1_000_000_002L);
		result.setTestName("threeLinesCostlyRun");
		result.setDescription("only three Lines, best solution to put a printf after each line and do only one run (seems logical to reduce the number of runs)");
		return result;
	}	
	
	
	private static TestCase threeLinesCostlyTyping(){
		OSDTestCase result=new OSDTestCase(3, 1, 1_000_000_000, 2_000_000_001L);
		result.setTestName("threeLinesCostlyTyping");
		result.setDescription("only three Lines, best solution to put a printf after each line and do only one run (in worst case we will have to use two printfs anyhow)");
		return result;
	}	
	
	
	
	
	
	private static TestCase fourLines(){
		OSDTestCase result=new OSDTestCase(4, 1, 1, 4L);
		result.setTestName("forLines");
		result.setDescription("four lines, both possibilities are equal good: divide and conquer and putting printf after every line");
		return result;
	}	
	
	
	private static TestCase fourLinesCostly(){
		OSDTestCase result=new OSDTestCase(4, 1_000_000_000, 1_000_000_000, 4_000_000_000L);
		result.setTestName("forLinesCostly");
		result.setDescription("four lines, both possibilities are equal good: divide and conquer and putting printf after every line, but the costs are high -> longs are needed");
		return result;
	}	
	
	
	private static TestCase fourLineCostlyRun(){
		OSDTestCase result=new OSDTestCase(4, 1_000_000_000, 1, 1_000_000_003L);
		result.setTestName("forLinesCostlyRun");
		result.setDescription("four lines, because of the high costs for the run, printf after each line is better");
		return result;
	}	

	
	private static TestCase fourLineCostlyTyping(){
		OSDTestCase result=new OSDTestCase(4, 1, 1_000_000_000, 2_000_000_002L);
		result.setTestName("forLinesCostlyRun");
		result.setDescription("four lines, because of the high costs for the typing, divide and conquer is better");
		return result;
	}
	
	private static TestCase fourLineCostlierRun(){
		OSDTestCase result=new OSDTestCase(4, 101, 100, 401L);
		result.setTestName("forLinesCostlierRun");
		result.setDescription("four lines, because of the slightly higher costs for the run, printf after each line is better");
		return result;
	}
	
	
	private static TestCase fourLineCostlierTyping(){
		OSDTestCase result=new OSDTestCase(4, 100, 101, 402L);
		result.setTestName("forLinesCostlierTyping");
		result.setDescription("four lines, because of the slightly higher costs for the typing, divide and conquer is better");
		return result;
	}
	
	private static TestCase fiveLineCosts(){
		OSDTestCase result=new OSDTestCase(5, 1, 1, 5L);
		result.setTestName("fiveLines");
		result.setDescription("equal costs -> [first step divide in two, second step put printf after each line] or [put printf after every line] are equal");
		return result;
	}	
	
	private static TestCase fiveLineCosts2(){
		OSDTestCase result=new OSDTestCase(5, 1, 10, 32L);
		result.setTestName("fiveLinesHigherTypingCosts");
		result.setDescription("as long as typing costlier than the run -> first step divide in two, second step put printf after each line");
		return result;
	}
	
	
	private static TestCase fiveLineCosts3(){
		OSDTestCase result=new OSDTestCase(5, 2, 1, 6L);
		result.setTestName("fiveLinesHigherRunCosts");
		result.setDescription("printf after each line is the best option here");
		return result;
	}
	
	
	private static TestCase fiveLineCosts4(){
		OSDTestCase result=new OSDTestCase(5, 6, 5, 26L);
		result.setTestName("fiveLinesHigherRunCosts");
		result.setDescription("printf after each line is the best option if running costs are higher");
		return result;
	}	
	
	
	private static TestCase nineLines(){
		OSDTestCase result=new OSDTestCase(9, 1, 1, 6L);
		result.setTestName("nineLinesEqualCosts");
		result.setDescription("divide in three parts, than printf after each line");
		return result;
	}
	
	private static TestCase nineLinesTypingHigher(){
		OSDTestCase result=new OSDTestCase(9, 1, 2, 10L);
		result.setTestName("nineLinesTypingHigher");
		result.setDescription("for higher typing costs: divide in three parts, than printf after each line");
		return result;
	}
	
	private static TestCase nineLinesRunSlightlyHigher(){
		OSDTestCase result=new OSDTestCase(9, 11, 10, 62L);
		result.setTestName("nineLinesTypingHigher");
		result.setDescription("for slightly higher running  costs: divide in three parts, than printf after each line (it is not worth to put printf after each line)");
		return result;
	}
	
	
	private static TestCase nineLinesRunUnderCritical(){
		OSDTestCase result=new OSDTestCase(9, 39, 10, 118L);
		result.setTestName("nineLinesRunUnderCritical");
		result.setDescription("for higher running  costs: divide in three parts, than printf after each line (here it is still not worth to put printf after each line)");
		return result;
	}

	
	private static TestCase nineLinesRunOveCritical(){
		OSDTestCase result=new OSDTestCase(9, 41, 10, 121L);
		result.setTestName("nineLinesRunOverCrititcal");
		result.setDescription("the critical cost for run is reached - printf after each line");
		return result;
	}
	
	private static TestCase tenLinesEqual(){
		OSDTestCase result=new OSDTestCase(10, 1, 1, 7L);
		result.setTestName("tenLinesEqual");
		result.setDescription("nine is the biggest number with cost 6, ten the minimal with costs 7");
		return result;
	}
	
	
	private static TestCase twelweLinesEqual(){
		OSDTestCase result=new OSDTestCase(12, 1, 1, 7L);
		result.setTestName("twelweLinesEqual");
		result.setDescription("12 is the biggest number with cost 7, 13 the minimal with costs 8");
		return result;
	}	
	
	
	private static TestCase thirteenLinesEqual(){
		OSDTestCase result=new OSDTestCase(13, 1, 1, 8L);
		result.setTestName("thirteenLinesEqual");
		result.setDescription("12 is the biggest number with cost 7, 13 the minimal with costs 8");
		return result;
	}	

	
	
	private static TestCase checkFor973(){
		OSDTestCase result=new OSDTestCase(972, 1001, 999, 18993);
		result.setTestName("checkFor973");
		result.setDescription("972 is the biggest line cnt with 18993 as answer");
		return result;
	}	
	
	
	private static TestCase unique973(){
		OSDTestCase result=new OSDTestCase(973, 1001, 999, 19990);
		result.setTestName("unique973");
		result.setDescription("there is only one way to get the smallest answer. Interesting: in every step 3 typed lines (1 is something you would expect)");
		return result;
	}
	
	private static TestCase typeAfterEveryLine(){
		OSDTestCase result=new OSDTestCase(29918, 400_000_000, 3, 400089751L);
		result.setTestName("typeAfterEveryLine");
		result.setDescription("diffence too big - type after every line");
		return result;
	}
	
	
	private static TestCase unique3073(){
		OSDTestCase result=new OSDTestCase(3073, 2001, 999, 29985);
		result.setTestName("unique3073");
		result.setDescription("there is only one way to get the smallest answer. Interesting: in every step 4 typed lines");
		return result;
	}
	
	private static TestCase max33(){
		OSDTestCase result=new OSDTestCase(177147, 1, 1, 33L);
		result.setTestName("max33");
		result.setDescription("biggest line cnt with costs 33");
		return result;
	}
	
	
	private static TestCase min34(){
		OSDTestCase result=new OSDTestCase(177148, 1, 1, 34L);
		result.setTestName("max33");
		result.setDescription("smallest line count with costs 34");
		return result;
	}
	
	private static TestCase max41(){
		OSDTestCase result=new OSDTestCase(82944, 2, 1, 41L);
		result.setTestName("max33");
		result.setDescription("biggest line cnt with costs 41");
		return result;
	}
	
	private static TestCase differentTypedCount(){
		OSDTestCase result=new OSDTestCase(200705, 1000001,99999, 10099965L);
		result.setTestName("differentTypedCount");
		result.setDescription("4,6,7,8,9 typed lines needed");
		return result;
	}
	
	
	
	
	private static TestCase min42(){
		OSDTestCase result=new OSDTestCase(82945, 2, 1, 42L);
		result.setTestName("max33");
		result.setDescription("smallest line count with costs 42, to reach this mostly 2 line must be typed but sometimes 3 and 4");
		return result;
	}
	
	
	
	private static TestCase bigDiffManyTyped79508(){
		OSDTestCase result=new OSDTestCase(79508, 200,3, 981L);
		result.setTestName("bigDiffManyTyped79508");
		result.setDescription("46 typed lines needed");
		return result;
	}
	
	
	private static TestCase check79508(){
		OSDTestCase result=new OSDTestCase(79507, 200,3, 978L);
		result.setTestName("check79508");
		result.setDescription("just cheking whether jump of costs is registered from 79507->79508");
		return result;
	}
	
	private static TestCase biggerNumberOfLines439401(){
		OSDTestCase result=new OSDTestCase(	439401, 200,3, 1100L);
		result.setTestName("biggerNumberOfLines439401");
		result.setDescription("46 typed lines needed");
		return result;
	}
	
	
	private static TestCase check439401(){
		OSDTestCase result=new OSDTestCase(439400, 200,3, 1097L);
		result.setTestName("check439401");
		result.setDescription("just cheking whether jump of costs is registered from 439400->439401");
		return result;
	}
	
	
	private static TestCase biggerNumberOfLines194482(){
		OSDTestCase result=new OSDTestCase(	194482, 200,3, 1043L);
		result.setTestName("biggerNumberOfLines194482");
		result.setDescription("unique for rekursion downwards from 12156 (22 typed lines)");
		return result;
	}
	
	
	private static TestCase check194482(){
		OSDTestCase result=new OSDTestCase(194481, 200,3, 1040L);
		result.setTestName("check439401");
		result.setDescription("just cheking whether jump of costs is registered from 439400->439401");
		return result;
	}
	
	private static TestCase biggerNumberOfLines511759(){
		OSDTestCase result=new OSDTestCase(	511759, 200,3, 1112L);
		result.setTestName("biggerNumberOfLines194482");
		result.setDescription("relatively high number of code lines, mostly has to type 28  lines");
		return result;
	}
	
	
	private static TestCase check511759(){
		OSDTestCase result=new OSDTestCase(511758, 200,3, 1109L);
		result.setTestName("check511759");
		result.setDescription("just cheking whether jump of costs is registered from 511758->511759");
		return result;
	}
	
	
	private static TestCase long78733(){
		OSDTestCase result=new OSDTestCase(	78733, 999_999_999,666_666_666, 24333333309L);
		result.setTestName("long78733");
		result.setDescription("needs long...");
		return result;
	}
	
	
	private static TestCase check78733(){
		OSDTestCase result=new OSDTestCase(78732, 999_999_999,666_666_666, 23_999_999_976L);
		result.setTestName("check78733");
		result.setDescription("just cheking whether jump of costs is registered from 78732->78733");
		return result;
	}
	
	
	private static TestCase long194401(){
		OSDTestCase result=new OSDTestCase(194401, 999_999_999,222_666_222, 14_457_320_430L);
		result.setTestName("long194401");
		result.setDescription("needs long");
		return result;
	}
	
	
	private static TestCase check194401(){
		OSDTestCase result=new OSDTestCase(194400, 999_999_999,222_666_222, 14347985319L);
		result.setTestName("check194401");
		result.setDescription("just cheking whether jump of costs is registered from 194401->194401");
		return result;
	}
	
	
	
	private static TestCase long233281(){
		OSDTestCase result=new OSDTestCase(233281, 999_999_999,222_666_222, 14679986652L);
		result.setTestName("long233281");
		result.setDescription("needs long, unique way till 77761");
		return result;
	}
	
	
	private static TestCase check233281(){
		OSDTestCase result=new OSDTestCase(233280, 999_999_999,222_666_222,  14570651541L);
		result.setTestName("check233281");
		result.setDescription("just cheking whether jump of costs is registered from 233280->233281");
		return result;
	}
	
	
	private static TestCase prime75(){
		OSDTestCase result=new OSDTestCase(82945, 7, 5, 180L);
		result.setTestName("prime75");
		result.setDescription("run=5, type=7, both primes");
		return result;
	}
	
	
	private static TestCase checkPrime75(){
		OSDTestCase result=new OSDTestCase(82944, 7, 5,  178L);
		result.setTestName("checkPrime57");
		result.setDescription("just cheking whether jump of costs is registered from 82944->82945");
		return result;
	}
	
	
	
	
	private static TestCase prime7311(){
		OSDTestCase result=new OSDTestCase(117650, 73, 11, 845L);
		result.setTestName("prime7311");
		result.setDescription("run=73, type11, both primes");
		return result;
	}
	
	
	private static TestCase checkPrime7311(){
		OSDTestCase result=new OSDTestCase(117649, 73, 11, 834);
		result.setTestName("checkPrime57");
		result.setDescription("just cheking whether jump of costs is registered from 117649->117650");
		return result;
	}

	
	
	private static TestCase typingCostly(){
		OSDTestCase result=new OSDTestCase(1025, 1, 10, 119L);
		result.setTestName("runCostly2");
		result.setDescription("run=73, type11, both primes");
		return result;
	}
	
	
	private static TestCase checkTypingCostly(){
		OSDTestCase result=new OSDTestCase(1024, 1, 10, 110L);
		result.setTestName("checkTypingCostly");
		result.setDescription("just cheking whether jump of costs is registered from 1024->1025");
		return result;
	}

	
	
	private static TestCase timeOut1(){
		OSDTestCase result=new OSDTestCase(900_000, 300, 5);
		result.setTestName("timeOut1");
		result.setDescription("time out for N^2 solutions expected");
		return result;
	}

	
	
	private static TestCase timeOut2(){
		OSDTestCase result=new OSDTestCase(955_553, 400, 7);
		result.setTestName("timeOut2");
		result.setDescription("time out for N^2 solutions expected");
		return result;
	}
	
	
	
	private static TestCase timeOut3(){
		OSDTestCase result=new OSDTestCase(888_888, 500_000, 3);
		result.setTestName("timeOut3");
		result.setDescription("time out for N^2 solutions expected");
		return result;
	}

	
	private static TestCase timeOut4(){
		OSDTestCase result=new OSDTestCase(999_999, 500_000, 133);
		result.setTestName("timeOut4");
		result.setDescription("time out for N^2 solutions expected");
		return result;
	}

	
	private static TestCase need53(){
		OSDTestCase result=new OSDTestCase(2916, 200, 3, 718L);
		result.setTestName("need53");
		result.setDescription("needs to explore factor at least till 53 to get right the answer");
		return result;
	}

	
	private static TestCase need98(){
		OSDTestCase result=new OSDTestCase(970225, 15_573,37, 57597L);
		result.setTestName("need98");
		result.setDescription("needs to explore the factor at least till 98 to get the right answer (recursion depth is 3)");
		return result;
	}
	
	
	private static TestCase need138(){
		OSDTestCase result=new OSDTestCase(19321, 600, 3, 2028L);
		result.setTestName("need138");
		result.setDescription("needs to explore the factor at least till 138 to get the right answer");
		return result;
	}
	
	
	private static TestCase need220(){
		OSDTestCase result=new OSDTestCase(48841, 1000, 3, 3320L);
		result.setTestName("need220");
		result.setDescription("needs to explore factor at least till 220 to get the right answer");
		return result;
	}
	
	private static TestCase need606(){
		OSDTestCase result=new OSDTestCase(607*607, 1000, 1, 3212L);
		result.setTestName("need606");
		result.setDescription("needs to explore factor at least till 606 to get the right answer");
		return result;
	}

	
	private static TestCase need997(){
		OSDTestCase result=new OSDTestCase(996_004, 315_573,31, 692960L);
		result.setTestName("need997");
		result.setDescription("needs to explore factor at least till 997 to get the right answer");
		return result;
	}
	
	private static TestCase need999(){
		OSDTestCase result=new OSDTestCase(1_000_000, 15_0000, 7);
		result.setTestName("need999");
		result.setDescription("needs to explore factor at least till 999 to get the right answer");
		return result;
	}

}
