
public class LoginsTool {
	
	public static void main(String[] args) throws Exception{
		
		/* create test cases */
		TestCaseCreator creator=new LoginsTestCaseCreator();
		
		/* setting up TestWriter */
		TestCaseWriter.setWidthOfPrefix(2);
		TestCaseWriter.setStartingIndex(26);
		/* run */
		CommandLineProcessor.processCommandLine(args, creator);
		
	}

}
