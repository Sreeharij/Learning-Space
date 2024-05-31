export default function NotFound() {
    const styles = {
        display: "flex",
        flexDirection: "column",
        justifyContent: "center",
        alignItems: "center",
        fontSize: "1.2em",
        marginTop: "250px",
        height: "25vh",
        textAlign: "center",
        backgroundColor: "grey",
        color: "blue",
        padding: "100px",
        boxShadow: "0 4px 8px rgba(0, 0, 0, 0.1)",
        borderRadius: "8px",
        border: "10px solid black",
    };

    const headingStyle = {
        fontSize: "2.5em",
        marginBottom: "10px",
    };

    const paragraphStyle = {
        fontSize: "1.2em",
    };

    return (
        <div style={styles}>
            <h2 style={headingStyle}>Page not found</h2>
            <p style={paragraphStyle}>Resource KaanmaanIlla</p>
        </div>
    );
}
