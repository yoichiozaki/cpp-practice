class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        canonicals = set()
        for email in emails:
            (local, domain) = email.split("@")
            local = local.split("+")[0].replace(".", "")
            canonicals.add(local + "@" + domain)
        return len(canonicals)
