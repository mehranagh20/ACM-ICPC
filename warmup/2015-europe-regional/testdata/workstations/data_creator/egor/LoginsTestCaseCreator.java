import java.util.Collection;
import java.util.LinkedList;


public class LoginsTestCaseCreator implements TestCaseCreator{
	public Collection<TestCase> createSamples(){
		Collection<TestCase> samples=new LinkedList<TestCase>();
		
		return samples;
	}
	
	public Collection<TestCase> createWrong(){
		Collection<TestCase> wrongs=new LinkedList<TestCase>();	
		return wrongs;
	}
	

	
	public Collection<TestCase> createSecret(){
		Collection<TestCase> secrets=new LinkedList<TestCase>();

		secrets.add(inTheMiddle());
		secrets.add(inTheMiddle2());
		secrets.add(inTheMiddle3());
		secrets.add(allResearcherEqual());
		secrets.add(allResearcherEqualButTwo());
		secrets.add(allResearcherEqualButTwoOneSaved());
		secrets.add(twoPartitions());
		
		return secrets;
	}
	
	
	private static TestCase allResearcherEqual(){
		Collection<LoginsTestCase.Session> sessions=new LinkedList<>();
		for(int i=0;i<LoginsTestCase.MAX_NUMBER_OF_RESEARCHER;i++)
			sessions.add(new LoginsTestCase.Session(LoginsTestCase.MAX_TIME, LoginsTestCase.MAX_TIME));
		
		LoginsTestCase result=new LoginsTestCase(5, sessions, 0);
		result.setTestName("allResearcherEqual");
		result.setDescription(LoginsTestCase.MAX_NUMBER_OF_RESEARCHER + " researchers come at the same time");
		return result;
	}

	
	private static TestCase allResearcherEqualButTwo(){
		Collection<LoginsTestCase.Session> sessions=new LinkedList<>();
		sessions.add(new LoginsTestCase.Session(LoginsTestCase.MIN_TIME, LoginsTestCase.MIN_TIME));
		sessions.add(new LoginsTestCase.Session(LoginsTestCase.MAX_TIME, LoginsTestCase.MAX_TIME));
		for(int i=2;i<LoginsTestCase.MAX_NUMBER_OF_RESEARCHER;i++)
			sessions.add(new LoginsTestCase.Session(LoginsTestCase.MAX_TIME/2, LoginsTestCase.MAX_TIME/4));
		
		LoginsTestCase result=new LoginsTestCase(5, sessions, 0);
		result.setTestName("allResearcherEqualButTwo");
		result.setDescription((LoginsTestCase.MAX_NUMBER_OF_RESEARCHER-2) + " researchers come at the same time, one earlier and one later");
		return result;
	}

	private static TestCase allResearcherEqualButTwoOneSaved(){
		Collection<LoginsTestCase.Session> sessions=new LinkedList<>();
		sessions.add(new LoginsTestCase.Session(LoginsTestCase.MIN_TIME, LoginsTestCase.MIN_TIME));
		sessions.add(new LoginsTestCase.Session(LoginsTestCase.MAX_TIME, LoginsTestCase.MAX_TIME));
		for(int i=2;i<LoginsTestCase.MAX_NUMBER_OF_RESEARCHER;i++)
			sessions.add(new LoginsTestCase.Session(LoginsTestCase.MAX_TIME/2, LoginsTestCase.MAX_TIME/2));
		
		LoginsTestCase result=new LoginsTestCase(5, sessions, 1);
		result.setTestName("allResearcherEqualButTwoOneSaved");
		result.setDescription((LoginsTestCase.MAX_NUMBER_OF_RESEARCHER-2) + " researchers come at the same time, one earlier and one later, the later one might not be escorted");
		return result;
	}
	
	
	private static TestCase twoPartitions(){
		Collection<LoginsTestCase.Session> sessions=new LinkedList<>();
		int M=22;
		for(int i=0;i<LoginsTestCase.MAX_NUMBER_OF_RESEARCHER/2;i++)
			sessions.add(new LoginsTestCase.Session(1, LoginsTestCase.MAX_TIME/2));
		for(int i=0;i<LoginsTestCase.MAX_NUMBER_OF_RESEARCHER/2;i++)
			sessions.add(new LoginsTestCase.Session( LoginsTestCase.MAX_TIME/2+2, LoginsTestCase.MAX_TIME));
		
		LoginsTestCase result=new LoginsTestCase(M, sessions, LoginsTestCase.MAX_NUMBER_OF_RESEARCHER/2);
		result.setTestName("twoPartitions");
		result.setDescription((LoginsTestCase.MAX_NUMBER_OF_RESEARCHER/2) + " come at first and " + (LoginsTestCase.MAX_NUMBER_OF_RESEARCHER/2) + " come and might not be escorted");
		return result;
	}
	

	private static TestCase inTheMiddle(){
		Collection<LoginsTestCase.Session> sessions=new LinkedList<>();
		for(int i=0;i<5;i++)
			sessions.add(new LoginsTestCase.Session(1, 1));
		for(int i=0;i<5;i++)
			sessions.add(new LoginsTestCase.Session(3, 3));
		for(int i=0;i<5;i++)
			sessions.add(new LoginsTestCase.Session(100, 1));
		
		LoginsTestCase result=new LoginsTestCase(1, sessions, 5);
		result.setTestName("inTheMiddle");
		result.setDescription("if only value and not value+1 is searched after, it might be we don't see all elements with value");
		return result;
	}
	
	private static TestCase inTheMiddle2(){
		Collection<LoginsTestCase.Session> sessions=new LinkedList<>();
		for(int i=0;i<50;i++)
			sessions.add(new LoginsTestCase.Session(1, 1));
		for(int i=0;i<23;i++)
			sessions.add(new LoginsTestCase.Session(3, 3));
		for(int i=0;i<50;i++)
			sessions.add(new LoginsTestCase.Session(100, 1));
		
		LoginsTestCase result=new LoginsTestCase(1, sessions, 23);
		result.setTestName("inTheMiddle2");
		result.setDescription("if only value and not value+1 is searched after, it might be we don't see all elements with value");
		return result;
	}
	
	private static TestCase inTheMiddle3(){
		Collection<LoginsTestCase.Session> sessions=new LinkedList<>();
		for(int i=0;i<50;i++)
			sessions.add(new LoginsTestCase.Session(1, 1));
		for(int i=0;i<60;i++)
			sessions.add(new LoginsTestCase.Session(3, 3));
		for(int i=0;i<50;i++)
			sessions.add(new LoginsTestCase.Session(100, 1));
		
		LoginsTestCase result=new LoginsTestCase(1, sessions, 50);
		result.setTestName("inTheMiddle3");
		result.setDescription("if only value and not value+1 is searched after, it might be we don't see all elements with value");
		return result;
	}
}
