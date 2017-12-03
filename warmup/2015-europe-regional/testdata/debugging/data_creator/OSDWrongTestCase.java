
public class OSDWrongTestCase extends OSDTestCase{
	
	OSDWrongTestCase(int lineCount, int runningTime, int typingTime){
		super(lineCount, runningTime, typingTime, -1L);//we don't really care about result
	}
	
	//no problems with wrong inputs...
	public String inputIsConsistent(){
		return null;
	}

}
