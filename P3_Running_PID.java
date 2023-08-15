import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class TopParse {
    public static void main(String[] args) {
        String filePath = "top_output.txt"; // Replace with the actual file path

        try (BufferedReader myReader = new BufferedReader(new FileReader(filePath))) {
            String line;
            boolean parsingStarted = false;

            // Read each line from the file
            while ((line = myReader.readLine()) != null) {
                if (line.trim().startsWith("PID")) {
                    parsingStarted = true;
                    continue;
                }

                if (parsingStarted) {
                    String[] parts = line.trim().split("\\s+");
                    if (parts.length >= 11) {
                        String myPid = parts[0]; // Extract PID
                        String myUser = parts[1]; // Extract User
                        System.out.println("PID: " + myPid + ", User: " + myUser);
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
