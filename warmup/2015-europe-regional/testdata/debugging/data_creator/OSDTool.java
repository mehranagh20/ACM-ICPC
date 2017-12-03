

public class OSDTool {

	public static void main(String[] args) throws Exception{
		
		TestCaseCreator creator=new OSDTestCaseCreator();
		
		CommandLineProcessor.processCommandLine(args, creator);
		
	}

}
