import java.util.Collection;
import java.util.LinkedList;
import java.util.List;


public class LoginsTestCase  extends NamedTestCase{


	  static public final int MIN_TIME_TIL_LOGOFF = 1;
	  static public final int MAX_TIME_TIL_LOGOFF = 100;
	  
	  static public final int MIN_TIME = 1;
	  static public final int MAX_TIME = 10_000;
	  
	  static public final int MIN_NUMBER_OF_RESEARCHER = 1;
	  static public final int MAX_NUMBER_OF_RESEARCHER = 300_000;
	  
      public static class Session{
    	  public int arrivalTime;
    	  public int sessionLength;
    	  
		public Session(int arrivalTime, int sessionLength) {
			super();
			this.arrivalTime = arrivalTime;
			this.sessionLength = sessionLength;
		}  
		
		boolean isCorrect(){
			return arrivalTime>=MIN_TIME && arrivalTime<=MAX_TIME && sessionLength>=MIN_TIME && sessionLength<=MAX_TIME;
		}
		
		public String toString(){
			return arrivalTime+" "+sessionLength;
		}
    	  
      }
	  private List<Session> sessions;
	  private int M;
	  private int result;

	  public LoginsTestCase(int M,  Collection<Session> researchers, int result){
		  
		  super();
		  
		  this.M=M;
		  this.result=result;
		  this.sessions=new LinkedList<Session>();
		  sessions.addAll(researchers);
	  }
	  
		
	  public String inputIsConsistent(){
		    if(MIN_TIME_TIL_LOGOFF>M || MAX_TIME_TIL_LOGOFF<M)
		    	return "M is wrong";
		    
		    if(sessions.size()<MIN_NUMBER_OF_RESEARCHER || MAX_NUMBER_OF_RESEARCHER<sessions.size())
		    	return "number of researchers wrong";
		    for (Session session:sessions)
		    	if(!session.isCorrect())
		    		return "a session is not correct";
		    
			return null;
	  }
		
	  public Collection<String> getInput(){
		   Collection<String> res=new LinkedList<String>();
		   res.add(sessions.size()+" "+M);
		   for(Session session: sessions)
			   res.add(session.toString());
		   return res;
	  }

	  
	  public Collection<String> getResult(){
		  Collection<String> res=new LinkedList<String>();
		  res.add(Long.toString(result));
		  return res;
	  }

	}
