import java.util.Collection;
import java.util.LinkedList;


public class OSDTestCase extends NamedTestCase{


  static public final int MIN_LINE_COUNT = 1;
  static public final int MAX_LINE_COUNT = 1_000_000;
  
  static public final int MIN_RUNNING_TIME = 1;
  static public final int MAX_RUNNING_TIME = 1_000_000_000;
  
  static public final int MIN_TYPING_TIME = 1;
  static public final int MAX_TYPING_TIME = 1_000_000_000;
  

  private int lineCount;
  private int runningTime;
  private int typingTime;
  
  private long result;

  public OSDTestCase(int lineCount, int runningTime, int typingTime, long result){
	  
	  super();
	  
	  this.lineCount=lineCount;
	  this.runningTime=runningTime;
	  this.typingTime=typingTime;
	  
	  this.result=result;
  }
  
  public OSDTestCase(int lineCount, int runningTime, int typingTime){
	  this(lineCount, runningTime, typingTime, 
		    OSDSolver.solveProblem(lineCount, runningTime, typingTime));
  }
	
  public String inputIsConsistent(){
	    if(MIN_LINE_COUNT>lineCount || MAX_LINE_COUNT<lineCount)
	    	return "Line count wrong";
	    
	    if(MIN_RUNNING_TIME>runningTime || MAX_RUNNING_TIME<runningTime)
	    	return "running time wrong";
	    
	    if(MIN_TYPING_TIME>typingTime || MAX_RUNNING_TIME<typingTime)
	    	return "typing time";
	    
		return null;
  }
	
  public Collection<String> getInput(){
	   Collection<String> res=new LinkedList<String>();
	   res.add(lineCount+" "+runningTime+" "+typingTime);
	   return res;
  }

  
  public Collection<String> getResult(){
	  Collection<String> res=new LinkedList<String>();
	  res.add(Long.toString(result));
	  return res;
  }

}
