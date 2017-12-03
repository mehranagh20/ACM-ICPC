import java.util.Collection;
import java.util.LinkedList;
import java.util.Random;


public class OSDRandomFileCreator {
	
	Random r;
	int maxN;
	int maxRT;
	int maxTT;
	String names;
	
	
	public OSDRandomFileCreator(int seed, int MAX_N, int MAX_RUN_TIME, int MAX_TYPE_TIME, String names) {
		r=new Random(seed);
		maxN=MAX_N;
		maxRT=MAX_RUN_TIME;
		maxTT=MAX_TYPE_TIME;
		this.names=names;
	}
	
	Collection<TestCase> createTestCases(int count){
		Collection<TestCase> result=new LinkedList<TestCase>();
		for(int i=0;i<count;i++){
			OSDTestCase testCase=new OSDTestCase(r.nextInt(maxN)+1, r.nextInt(maxRT)+1, r.nextInt(maxTT)+1);
			testCase.setTestName("random_"+names);
			result.add(testCase);
			
		}	
		return result;		
	}
}
